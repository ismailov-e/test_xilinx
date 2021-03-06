/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2014 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */

/**@file*/

#include "vbx_copyright.h"
VBXCOPYRIGHT( api )

#include "vbx.h"
#include "vbx_port.h"



// --------------------------------------------------------
// System-wide global variables

#if VBX_USE_GLOBAL_MXP_PTR
vbx_mxp_t *vbx_mxp_ptr;
#endif

// --------------------------------------------------------
// Local variables
//#define vbx_sp        (this_mxp->sp)
#define sp_stack      (this_mxp->spstack)
#define sp_stack_top  (this_mxp->spstack_top)
#define sp_stack_max  (this_mxp->spstack_max)

// --------------------------------------------------------
// System-wide initialization

/** Initialize MXP processor
 *
 * param[out] this_mxp
 */
void _vbx_init( vbx_mxp_t *this_mxp )
{
	// initialize the sp stack
	// max = depth of scratchpad
	this_mxp->spstack_max = (int)( this_mxp->scratchpad_size / this_mxp->vector_lanes );
	this_mxp->spstack_top = 0;
// don't malloc spstack for MicroBlaze simulation, because axi_bram isn't
// large enough.
#if !VBX_DEBUG_NO_SPSTACK
	if( !this_mxp->spstack ) {
		int spstack_size = this_mxp->spstack_max * sizeof(vbx_void_t *);
		this_mxp->spstack = (vbx_void_t **)malloc( spstack_size );
		if ( !this_mxp->spstack ) {
			VBX_PRINTF("ERROR: failed to malloc %d bytes for spstack.\n", spstack_size);
			VBX_FATAL(__LINE__, __FILE__, -1);
		}
#if VBX_DEBUG_MALLOC
		printf("_vbx_init: malloc %d bytes\n", spstack_size);
#endif
	}
#endif

#if VBX_USE_GLOBAL_MXP_PTR
	// Must be set before any MXP instructions can be issued!
	vbx_mxp_ptr = this_mxp;
#endif

	// FIXME WARNING: the function call below only works for uniprocessors
	// The function must only be called by the CPU that owns the accelerator
	// described by 'mxp' instance.
	vbx_set_reg( VBX_REG_MXPCPU, (int)this_mxp ); // FIXME

	this_mxp->init = 1;
}


// --------------------------------------------------------
// Allocate and deallocate scratchpad memory.

static void print_sp_malloc_null()
{	printf( "WARNING: vbx_sp_malloc() requested 0 bytes.\n" );
}

static void print_sp_malloc_full( size_t num_bytes, size_t padded_bytes )
{
	printf( "ERROR: vbx_sp_malloc() requested %d bytes, ", (int)num_bytes );
	printf( "aligned needs %d bytes, ",       (int)padded_bytes );
	printf( "but only %d bytes available.\n", (int)vbx_sp_getfree() );
}

vbx_void_t *vbx_sp_malloc_debug( int LINE,const char *FNAME, size_t num_bytes )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->init ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	}

	// pad to scratchpad width to reduce occurrence of false hazards
	size_t padded = VBX_PAD_UP( num_bytes, this_mxp->scratchpad_alignment_bytes );
	size_t freesp = (size_t)(this_mxp->scratchpad_end - this_mxp->sp); //VBX_SCRATCHPAD_END - (size_t)vbx_sp; // vbx_sp_getfree();

	vbx_void_t  *result = NULL;
	if( VBX_DEBUG_LEVEL && (num_bytes==0) ) {
		print_sp_malloc_null();
	} else if( VBX_DEBUG_LEVEL && freesp < padded ) {
		print_sp_malloc_full( num_bytes, padded );
	} else if( num_bytes > 0  &&  freesp >= padded ) {
		result        = this_mxp->sp;
		this_mxp->sp += padded;
#if VBX_DEBUG_SP_MALLOC
		printf("sp_malloc %d bytes padded to %d, sp=0x%08x\n", num_bytes, padded, this_mxp->sp);
#endif
	}

	if( !result ) {
		VBX_FATAL(LINE,FNAME,-1);
	}
	return result;
}

vbx_void_t *vbx_sp_malloc_nodebug( size_t num_bytes )
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		return vbx_sp_malloc_debug( __LINE__, __FILE__, num_bytes );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();

	// check for valid argument values
	if( !this_mxp  ||  num_bytes==0 )
		return NULL;

	// add padding and allocate
	// pad to scratchpad width to reduce occurrence of false hazards
	size_t padded = VBX_PAD_UP( num_bytes, this_mxp->scratchpad_alignment_bytes );
	vbx_void_t *old_sp = this_mxp->sp;
	this_mxp->sp += padded;

	// scratchpad full
	if( this_mxp->sp > this_mxp->scratchpad_end ) {
		this_mxp->sp = old_sp;
		return NULL;
	}

	// success
	return old_sp;
}

void vbx_sp_free_debug( int LINE, const char *FNAME )
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp )  {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else {
		this_mxp->sp = this_mxp->scratchpad_addr;
		this_mxp->spstack_top = 0;
	}
}

void vbx_sp_free_nodebug()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp )  {
		this_mxp->sp = this_mxp->scratchpad_addr;
		this_mxp->spstack_top = 0;
	}
}


// --------------------------------------------------------
// Scratchpad manipulation routines

int vbx_sp_getused()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int used = 0;
	if( this_mxp )
		used = (int)(this_mxp->sp - this_mxp->scratchpad_addr);
	return used;
}

int vbx_sp_getfree()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int free = 0;
	if( this_mxp )
		free = (int)(this_mxp->scratchpad_end - this_mxp->sp);
	return free;
}

vbx_void_t *vbx_sp_get()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	return this_mxp ? this_mxp->sp : NULL;
}

void vbx_sp_set_debug( int LINE, const char *FNAME, vbx_void_t *new_sp )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp )  {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( (this_mxp->scratchpad_addr <= new_sp && new_sp <= this_mxp->scratchpad_end)
	           && VBX_IS_ALIGNED(new_sp, 4) ) {
		this_mxp->sp = new_sp;
	} else {
		VBX_PRINTF( "ERROR: attempt to set scratchpad to illegal or unaligned address 0x%08lx.\n", (long int)new_sp );
		VBX_FATAL(LINE,FNAME,-1);
	}
}

void vbx_sp_set_nodebug( vbx_void_t *new_sp )
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		vbx_sp_set_debug( __LINE__, __FILE__, new_sp );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp
	           && (this_mxp->scratchpad_addr <= new_sp && new_sp <= this_mxp->scratchpad_end)
	           && VBX_IS_ALIGNED(new_sp, 4) ) {
		this_mxp->sp = new_sp;
	}
}


void vbx_sp_push_debug( int LINE, const char *FNAME )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->spstack ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( this_mxp->spstack_top >= this_mxp->spstack_max ) {
		VBX_PRINTF("ERROR: attempted to use vbx_sp_push() past top of stack.\n");
		VBX_FATAL(LINE,FNAME,-1);
	}
	this_mxp->spstack[ this_mxp->spstack_top++ ] = this_mxp->sp;
}


void vbx_sp_pop_debug( int LINE, const char *FNAME )

{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->spstack ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( this_mxp->spstack_top==0 ) {
		VBX_PRINTF("ERROR: attempted vbx_sp_pop() before first push.\n");
		VBX_FATAL(LINE,FNAME,-1);
	}
	this_mxp->sp = this_mxp->spstack[ --this_mxp->spstack_top ];
}


// --------------------------------------------------------
// Memory allocation routines

// Allocate and deallocate memory that is shared between host CPU and vector processor.
// This shared memory is (1) uncached and (2) aligned to a Data cache linesize so a
// fraction of the line is not cachable.
//
// The alloca() version allocates from the local stack. It will be automatically freed when the
// current function returns.

void *vbx_shared_alloca_nodebug( size_t num_bytes, void *p )
{
	void *alloced_ptr;
	void *aligned_ptr = NULL;

	unsigned int padding = VBX_PADDING();

	alloced_ptr = (void *)p;
	if( alloced_ptr ) {
		aligned_ptr = (void *)VBX_PAD_UP( alloced_ptr, padding );
		aligned_ptr = (void *)vbx_remap_uncached_flush( aligned_ptr, num_bytes );
	}

	return aligned_ptr;
}

void *vbx_shared_alloca_debug( int LINE, const char *FNAME, size_t num_bytes, void *p )
{
	return vbx_shared_alloca_nodebug( num_bytes, p );
}

void *vbx_shared_malloc( size_t num_bytes )
{
	void *alloced_ptr;
	void *aligned_ptr = NULL;

	unsigned int padding = VBX_PADDING();

#if VBX_DEBUG_MALLOC
	printf("shared_malloc %d bytes\n", num_bytes);
#endif
	alloced_ptr = (void *)vbx_uncached_malloc(num_bytes+sizeof(void*)+2*padding);
	if( alloced_ptr ) {
		aligned_ptr = (void *)VBX_PAD_UP( (alloced_ptr+sizeof(void*)), padding );
		*((void **)(aligned_ptr-sizeof(void*))) = alloced_ptr;
	}

	return aligned_ptr;
}


void vbx_shared_free(void *shared_ptr)
{
	void *alloced_ptr;
	if( shared_ptr ) {
		alloced_ptr = *((void **)(shared_ptr-sizeof(void*)));
		vbx_uncached_free(alloced_ptr);
	}
}

int RUNTIME_CHECK_FAILED=0;
int runtime_check_suppress=~0;

#define RTC_printf(chk,...) if(runtime_check_suppress&chk)printf(__VA_ARGS__)

void print_sp_range(int enable){
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	RTC_printf(enable,"note: scratchpad range is [0x%08X - 0x%08X]\n",
		       (unsigned)this_mxp->scratchpad_addr,
		       (unsigned)this_mxp->scratchpad_end);
}
void vbx_generic_check(int dest_len, void* dest, int srcA_len,
	                  void* srcA, int srcB_len,void* srcB, vinstr_t v_op)
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	unsigned base = (unsigned) this_mxp->scratchpad_addr;
	unsigned end = (unsigned) this_mxp->scratchpad_end;
	if((unsigned)dest < base ||
	   (unsigned)dest + dest_len >end){
		RTC_printf(RT_CHECK_SP_BOUND,
		           "warning: Destination range [0x%08X - 0x%08X ] is not contained in scratchpad\n\t",
			       (unsigned)dest,(unsigned)dest +dest_len);
		print_sp_range(RT_CHECK_SP_BOUND);
		RUNTIME_CHECK_FAILED=1;
	}else if((unsigned)srcA < base ||
	         (unsigned)srcA + srcA_len >end){
		RTC_printf(RT_CHECK_SP_BOUND,
		           "warning: Source A range [0x%08X - 0x%08X ] is not contained in scratchpad\n\t",
			       (unsigned)srcA,(unsigned)srcA +srcA_len);
		print_sp_range(RT_CHECK_SP_BOUND);
		RUNTIME_CHECK_FAILED=1;
	}else if(((unsigned)srcA < base ||
	          (unsigned)srcA + srcB_len >end)&& v_op != VMOV){
		RTC_printf(RT_CHECK_SP_BOUND,
		           "warning: Source B range [0x%08X - 0x%08X ] is not contained in scratchpad\n\t",
			       (unsigned)srcB,(unsigned)srcA +srcB_len);
		print_sp_range(RT_CHECK_SP_BOUND);
		RUNTIME_CHECK_FAILED=1;
	}
}
void vbx_check(size_t dest_size, void* dest, size_t srcA_size,
	               void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;
	vbx_get_vl(&vl);
	vbx_generic_check(vl*dest_size,dest,vl*srcA_size,srcA,vl*srcB_size,srcB,v_op);
}
void vbx_2D_check(size_t dest_size, void* dest, size_t srcA_size,
	                  void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;
	vbx_get_vl(&vl);

	int nrows, dinc2,ainc2,binc2;
	vbx_get_2D(&nrows,&dinc2,&ainc2,&binc2);
	 //decrement because if nrows is 2 then we increment 1 time
	nrows-=1;
	int d_len=vl*dest_size+nrows*dinc2;
	int a_len=vl*srcA_size+nrows*ainc2;
	int b_len=vl*srcB_size+nrows*binc2;
	vbx_generic_check(d_len,dest,a_len,srcA,b_len,srcB,v_op);
}
void vbx_3D_check(size_t dest_size, void* dest, size_t srcA_size,
	                  void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;
	vbx_get_vl(&vl);
	int nrows, dinc2,ainc2,binc2;
	vbx_get_2D(&nrows,&dinc2,&ainc2,&binc2);
	int nmats, dinc3,ainc3,binc3;
	vbx_get_3D(&nmats,&dinc3,&ainc3,&binc3);
	 //decrement because if nrows is 2 then we increment 1 time
	nrows-=1;
	nmats-=1;
	int d_len=vl*dest_size+nrows*dinc2+nmats*dinc3;
	int a_len=vl*srcA_size+nrows*ainc2+nmats*ainc3;
	int b_len=vl*srcB_size+nrows*binc2+nmats*binc3;
	vbx_generic_check(d_len,dest,a_len,srcA,b_len,srcB,v_op);

}
void vbx_acc_check(size_t dest_size, void* dest, size_t srcA_size,
	                   void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;vbx_get_vl(&vl);
	vbx_generic_check(dest_size,dest,vl,srcA,vl,srcB,v_op);
}
void vbx_acc_2D_check(size_t dest_size, void* dest, size_t srcA_size,
	                      void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;
	vbx_get_vl(&vl);
	int nrows, dinc2,ainc2,binc2;
	vbx_get_2D(&nrows,&dinc2,&ainc2,&binc2);
	nrows-=1;
	int d_len=dest_size+nrows*dinc2;
	int a_len=vl*srcA_size+nrows*ainc2;
	int b_len=vl*srcB_size+nrows*binc2;
	vbx_generic_check(d_len,dest,a_len,srcA,b_len,srcB,v_op);

}
void vbx_acc_3D_check(size_t dest_size, void* dest, size_t srcA_size,
	                      void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	int vl ;
	vbx_get_vl(&vl);
	int nrows, dinc2,ainc2,binc2;
	vbx_get_2D(&nrows,&dinc2,&ainc2,&binc2);
	int nmats, dinc3,ainc3,binc3;
	nrows-=1;
	nmats-=1;
	vbx_get_3D(&nmats,&dinc3,&ainc3,&binc3);
	unsigned d_len=dest_size+nrows*dinc2+nmats*dinc3;
	unsigned a_len=vl*srcA_size+nrows*ainc2+nmats*ainc3;
	unsigned b_len=vl*srcB_size+nrows*binc2+nmats*binc3;
	vbx_generic_check(d_len,dest,a_len,srcA,b_len,srcB,v_op);
}

int addr_in_sp(void* addr)
{

	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	unsigned base = (unsigned) this_mxp->scratchpad_addr;
	unsigned end = (unsigned) this_mxp->scratchpad_end;
	return ((unsigned)addr>=base && (unsigned)addr <= end);
}
void dma_check(void* external, void* internal,int len){
	if ( addr_in_sp(external) || addr_in_sp(external+len)){
		RTC_printf(RT_CHECK_DMA,"warning: host buffer range [0x%08X - 0x%08X ] overlaps scratchpad\n",
		           (unsigned)external,(unsigned)external +len);
		print_sp_range(RT_CHECK_DMA);
		RUNTIME_CHECK_FAILED=1;
 	}
	if( !addr_in_sp(internal) || !addr_in_sp(internal+len)){
		RTC_printf(RT_CHECK_DMA,
		           "DMA Warning: MXP buffer [0x%08X - 0x%08X ] is not contained in scratchpad\n",
		       (unsigned)internal, (unsigned)internal+len);
		print_sp_range(RT_CHECK_DMA);
		RUNTIME_CHECK_FAILED=1;
	}
}
void vbx_dma_to_host_debug(void* external,void* internal, int len)
{
	dma_check(external,internal,len);
	vbx_dma_to_host_nodebug(external,internal,len);
}
void vbx_dma_to_vector_debug(void* internal,void* external, int len)
{
	dma_check(external,internal,len);
	vbx_dma_to_vector_nodebug(internal,external,len);
}

void vbx_set_vl_debug(int len)
{

	if ((unsigned)len >(unsigned)( VBX_GET_THIS_MXP()->scratchpad_size)){
		RTC_printf(RT_CHECK_VEC_LEN,
		           "vbx_set_vl warning: setting vector length =%d greater than scratchpad size=%d\n",
		           len,VBX_GET_THIS_MXP()->scratchpad_size);
		RUNTIME_CHECK_FAILED=1;
	}
	vbx_set_vl_nodebug(len);
}
void vbx_set_2D_debug(int nrows,int incd, int inca,int incb)
{
	int size= VBX_GET_THIS_MXP()->scratchpad_size;
	nrows--;	 //decrement because if nrows is 2 then we increment 1 time
	if (abs((unsigned)nrows*incd) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_2D warning: abx(nrows * dest_inc) > scratchpad_size (%d>%d)\n",
		           abs((unsigned)nrows*incd),size);
		RUNTIME_CHECK_FAILED=1;
	}if (abs((unsigned)nrows*inca) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_2D warning: abx(nrows * srcA_inc) > scratchpad_size (%d>%d)\n",
		           abs((unsigned)nrows*inca),size);
		RUNTIME_CHECK_FAILED=1;
	}if (abs((unsigned)nrows*incb) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_2D warning: abx(nrows * srcB_inc) > scratchpad_size (%d>%d)\n",
		           abs((unsigned)nrows*incb),size);
		RUNTIME_CHECK_FAILED=1;
	}
	vbx_set_2D_nodebug(nrows+1,incd,inca,incb);
}

void vbx_set_3D_debug(int nmats,int incd, int inca,int incb)
{
	int size= VBX_GET_THIS_MXP()->scratchpad_size;
	nmats--;	 //decrement because if nrows is 2 then we increment 1 time
	if (abs(nmats*incd) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_3D warning: abs(nmats * dest_inc) > scratchpad_size (%d>%d)\n",
		           abs(nmats*incd),size);
		RUNTIME_CHECK_FAILED=1;
	}if (abs(nmats*inca) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_3D warning: abs(nmats * srcA_inc) > scratchpad_size (%d>%d)\n",
		           abs(nmats*inca),size);
		RUNTIME_CHECK_FAILED=1;
	}if (abs(nmats*incb) >size){
		RTC_printf(RT_CHECK_VEC_LEN,"vbx_set_3D warning: abs(nmats * srcB_inc) > scratchpad_size (%d>%d)\n",
		           abs(nmats*incb),size);
	 RUNTIME_CHECK_FAILED=1;
	}
	vbx_set_3D_nodebug(nmats+1,incd,inca,incb);
}

//TODO:make this have finer grain warnings
void vbx_check_1D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	if ( dest>srcA  || (v_op!=VMOV && dest>srcB) ){
		RTC_printf(RT_CHECK_COP_FWD,"warning: possible copy forward hazard risk\n");
		RUNTIME_CHECK_FAILED=1;
	}
}
void vbx_check_2D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	vbx_check_1D_cop_fwd(dest_size,dest,srcA_size,srcA,srcB_size,srcB,v_op);
}
void vbx_check_3D_cop_fwd(size_t dest_size, void* dest, size_t srcA_size,
                          void* srcA, size_t srcB_size,void* srcB, vinstr_t v_op)
{
	vbx_check_1D_cop_fwd(dest_size,dest,srcA_size,srcA,srcB_size,srcB,v_op);
}
