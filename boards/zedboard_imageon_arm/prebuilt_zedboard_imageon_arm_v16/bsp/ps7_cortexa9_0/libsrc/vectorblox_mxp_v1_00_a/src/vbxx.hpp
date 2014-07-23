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

#ifndef __VBXX_HPP
#define __VBXX_HPP

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_2D( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_2D( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_2D( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_2D( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_2D( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_2D( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_2D( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_2D( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_2D( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_2D( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_2D( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_2D( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_2D( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_2D( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_2D( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_2D( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_2D( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_2D( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_2D( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_2D( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_2D( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_2D( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_2D( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_2D( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_2D( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_2D( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_2D( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_2D( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_2D( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_2D( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_2D( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_2D( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_2D( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_2D( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_2D( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_2D( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_2D( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_2D( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_2D( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_2D( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_2D( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_2D( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_2D( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_2D( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_2D( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_2D( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_2D( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_2D( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_2D( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_2D( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_2D( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_2D( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_2D( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_2D( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_2D( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_2D( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_2D( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_2D( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_2D( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_2D( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_2D( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_2D( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_2D( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_2D( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_2D( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_2D( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_2D( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_2D( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_2D( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_2D( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_2D( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_2D( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_2D( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_2D( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_2D( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_2D( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_2D( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_2D( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_2D( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_2D( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_2D( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_2D( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_2D( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_2D( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_2D( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_2D( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_2D( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_2D( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_2D( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_2D( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_2D( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_2D( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_2D( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_2D( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_2D( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_2D( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_2D( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_2D( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_2D( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_2D( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_2D( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_2D( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_2D( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_2D( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_2D( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_2D( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_2D( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_2D( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_2D( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_2D( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_2D( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_2D( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_2D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_2D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_2D( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_2D( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_2D( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_2D( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_2D( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_2D( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_2D( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_2D( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_2D( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_2D( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_2D( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_2D( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_2D( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_2D( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_2D( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_2D( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_2D( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_2D( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_2D( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_2D( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_2D( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_2D( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_2D( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_2D( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_2D( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_3D( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_3D( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_3D( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_3D( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_3D( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_3D( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_3D( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_3D( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_3D( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_3D( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_3D( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_3D( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_3D( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_3D( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_3D( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_3D( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_3D( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_3D( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_3D( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_3D( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_3D( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_3D( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_3D( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_3D( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_3D( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_3D( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_3D( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_3D( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_3D( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_3D( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_3D( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_3D( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_3D( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_3D( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_3D( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_3D( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_3D( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_3D( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_3D( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_3D( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_3D( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_3D( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_3D( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_3D( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_3D( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_3D( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_3D( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_3D( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_3D( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_3D( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_3D( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_3D( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_3D( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_3D( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_3D( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_3D( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_3D( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_3D( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_3D( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_3D( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_3D( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_3D( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_3D( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_3D( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_3D( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_3D( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_3D( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_3D( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_3D( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_3D( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_3D( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_3D( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_3D( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_3D( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_3D( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_3D( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_3D( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_3D( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_3D( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_3D( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_3D( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_3D( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_3D( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_3D( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_3D( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVB, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVB, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVB, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVB, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVB, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVB, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVB, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVB, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVB, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVB, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVB, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVB, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVB, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVB, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVB, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVB, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVB, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVB, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVB, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVB, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVBU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVBH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVBH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVBH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVBH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVBH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVBH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVBH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVBHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVBHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVBHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVBHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVBHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVBHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVBHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVBW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVBW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVBW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVBW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVBW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVBW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_byte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVBW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVBWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVBWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVBWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVBWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVBWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVBWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVBWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVBWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVBWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVBWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVBWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVBWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVBWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVBWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVBWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVBWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVBWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVBWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVBWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVBWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVBWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVBWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVBWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVBWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVBWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_ubyte_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVBWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVHB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVHB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVHB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVHB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVHB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVHB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVHB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVHBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVHBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVHBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVHBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVHBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVHBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVHBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVH, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVH, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVH, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVH, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVH, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVH, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVH, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVH, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVH, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVH, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVH, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVH, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVH, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVH, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVH, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVH, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVH, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVH, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVH, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVH, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVHU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVHW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVHW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVHW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVHW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVHW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVHW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_half_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVHW, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVHWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVHWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVHWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVHWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVHWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVHWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVHWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVHWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVHWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVHWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVHWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVHWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVHWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVHWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVHWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVHWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVHWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVHWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVHWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVHWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVHWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVHWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVHWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVHWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVHWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uhalf_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVHWU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWB, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWB, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWB, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWB, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWB, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWB, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWB, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWB, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWB, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWB, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWB, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWB, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWB, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWB, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWB, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVWB, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVWB, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVWB, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVWB, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVWB, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVWB, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWB, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWB, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWB, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWB, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVWB, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWBU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWBU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWBU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWBU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWBU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWBU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWBU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWBU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWBU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWBU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWBU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWBU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWBU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWBU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWBU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVWBU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVWBU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVWBU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVWBU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVWBU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVWBU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWBU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWBU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWBU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWBU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVWBU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWH, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWH, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWH, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWH, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWH, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWH, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWH, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWH, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWH, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWH, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWH, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWH, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWH, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWH, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWH, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVWH, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVWH, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVWH, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVWH, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVWH, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVWH, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWH, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWH, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWH, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWH, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVWH, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWHU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWHU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWHU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWHU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWHU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWHU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWHU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWHU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWHU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWHU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWHU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWHU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWHU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWHU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWHU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVWHU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVWHU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVWHU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVWHU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVWHU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVWHU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWHU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWHU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWHU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWHU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VMOV:
		vbxasm_acc_3D( VVWHU, VMOV, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVW, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVW, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVW, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVW, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVW, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVW, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVW, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVW, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVW, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVW, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVW, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVW, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVW, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVW, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVW, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVW, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVW, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVW, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVW, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVW, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVW, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVW, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVW, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVW, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVW, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVW, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVW, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVW, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVW, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVW, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVW, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVW, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVW, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVW, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVW, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVW, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVW, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVW, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVW, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVW, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVW, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVW, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVW, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVW, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVW, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWU, VADD, v_out, v_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWU, VSUB, v_out, v_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWU, VADDC, v_out, v_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWU, VSUBB, v_out, v_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWU, VABSDIFF, v_out, v_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWU, VMUL, v_out, v_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWU, VMULHI, v_out, v_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWU, VMULFXP, v_out, v_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWU, VAND, v_out, v_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWU, VOR, v_out, v_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWU, VXOR, v_out, v_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWU, VSHL, v_out, v_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWU, VSHR, v_out, v_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWU, VROTL, v_out, v_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWU, VROTR, v_out, v_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VVWU, VCMV_LEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VVWU, VCMV_GTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VVWU, VCMV_LTZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VVWU, VCMV_GEZ, v_out, v_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VVWU, VCMV_Z, v_out, v_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VVWU, VCMV_NZ, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWU, VCUSTOM0, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWU, VCUSTOM1, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWU, VCUSTOM2, v_out, v_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWU, VCUSTOM3, v_out, v_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VVWU, VADD, v_out, v_out, v_in1 );
		break;
	case VSUB:
		vbxasm_acc_3D( VVWU, VSUB, v_out, v_out, v_in1 );
		break;
	case VADDC:
		vbxasm_acc_3D( VVWU, VADDC, v_out, v_out, v_in1 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VVWU, VSUBB, v_out, v_out, v_in1 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VVWU, VABSDIFF, v_out, v_out, v_in1 );
		break;
	case VMUL:
		vbxasm_acc_3D( VVWU, VMUL, v_out, v_out, v_in1 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VVWU, VMULHI, v_out, v_out, v_in1 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VVWU, VMULFXP, v_out, v_out, v_in1 );
		break;
	case VAND:
		vbxasm_acc_3D( VVWU, VAND, v_out, v_out, v_in1 );
		break;
	case VOR:
		vbxasm_acc_3D( VVWU, VOR, v_out, v_out, v_in1 );
		break;
	case VXOR:
		vbxasm_acc_3D( VVWU, VXOR, v_out, v_out, v_in1 );
		break;
	case VSHL:
		vbxasm_acc_3D( VVWU, VSHL, v_out, v_out, v_in1 );
		break;
	case VSHR:
		vbxasm_acc_3D( VVWU, VSHR, v_out, v_out, v_in1 );
		break;
	case VROTL:
		vbxasm_acc_3D( VVWU, VROTL, v_out, v_out, v_in1 );
		break;
	case VROTR:
		vbxasm_acc_3D( VVWU, VROTR, v_out, v_out, v_in1 );
		break;
	case VMOV:
		vbxasm_acc_3D( VVWU, VMOV, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VVWU, VCUSTOM0, v_out, v_out, v_in1 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VVWU, VCUSTOM1, v_out, v_out, v_in1 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VVWU, VCUSTOM2, v_out, v_out, v_in1 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VVWU, VCUSTOM3, v_out, v_out, v_in1 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVB, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVB, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVB, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVB, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVB, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVB, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVB, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVB, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVB, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVB, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVB, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVB, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVB, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVB, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVB, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVB, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVB, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVB, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVB, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVB, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVBU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVBU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVBU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVBH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVBH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVBH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVBH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVBH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVBH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVBH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVBH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVBHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVBHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVBHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVBHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVBHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVBHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVBHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVBHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_byte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVBW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVBW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVBW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVBW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVBW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVBW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVBW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVBW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_ubyte_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVBWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVBWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVBWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVBWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVBWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVBWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVBWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVBWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVBWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVBWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVBWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVBWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVBWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVBWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVBWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVBWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVBWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVBWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVBWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVBWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVBWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVBWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVBWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVBWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVBWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVHB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVHB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVHB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVHB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVHB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVHB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVHB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVHB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVHBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVHBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVHBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVHBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVHBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVHBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVHBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVHBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVH, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVH, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVH, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVH, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVH, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVH, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVH, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVH, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVH, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVH, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVH, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVH, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVH, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVH, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVH, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVH, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVH, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVH, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVH, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVH, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVHU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVHU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVHU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_half_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVHW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVHW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVHW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVHW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVHW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVHW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVHW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVHW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uhalf_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVHWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVHWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVHWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVHWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVHWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVHWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVHWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVHWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVHWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVHWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVHWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVHWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVHWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVHWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVHWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVHWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVHWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVHWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVHWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVHWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVHWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVHWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVHWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVHWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVHWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWB, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWB, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWB, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWB, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWB, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWB, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWB, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWB, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVWB, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVWB, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWB, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWB, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWB, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWB, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWB, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVWB, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVWB, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVWB, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVWB, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVWB, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVWB, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWB, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWB, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWB, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWB, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWBU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWBU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWBU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWBU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWBU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWBU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWBU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWBU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVWBU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVWBU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWBU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWBU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWBU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWBU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWBU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVWBU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVWBU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVWBU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVWBU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVWBU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVWBU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWBU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWBU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWBU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWBU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWH, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWH, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWH, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWH, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWH, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWH, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWH, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWH, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVWH, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVWH, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWH, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWH, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWH, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWH, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWH, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVWH, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVWH, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVWH, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVWH, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVWH, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVWH, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWH, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWH, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWH, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWH, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWHU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWHU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWHU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWHU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWHU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWHU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWHU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWHU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVWHU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVWHU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWHU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWHU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWHU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWHU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWHU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVWHU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVWHU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVWHU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVWHU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVWHU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVWHU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWHU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWHU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWHU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWHU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_word_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVW, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVW, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVW, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVW, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVW, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVW, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVW, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVW, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVW, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVW, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVW, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVW, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVW, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVW, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVW, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVW, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVW, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVW, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVW, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVW, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVW, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVW, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVW, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVW, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVW, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVW, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVW, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVW, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVW, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVW, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVW, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVW, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVW, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVW, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVW, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVW, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVW, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVW, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVW, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVW, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVW, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVW, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVW, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVW, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVW, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_uword_t *v_in2 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,sizeof(*v_in2),v_in2,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWU, VADD, v_out, s_in1, v_in2 );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWU, VSUB, v_out, s_in1, v_in2 );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWU, VADDC, v_out, s_in1, v_in2 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWU, VSUBB, v_out, s_in1, v_in2 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWU, VABSDIFF, v_out, s_in1, v_in2 );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWU, VMUL, v_out, s_in1, v_in2 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWU, VMULHI, v_out, s_in1, v_in2 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWU, VMULFXP, v_out, s_in1, v_in2 );
		break;
	case VAND:
		vbxasm_acc_3D( SVWU, VAND, v_out, s_in1, v_in2 );
		break;
	case VOR:
		vbxasm_acc_3D( SVWU, VOR, v_out, s_in1, v_in2 );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWU, VXOR, v_out, s_in1, v_in2 );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWU, VSHL, v_out, s_in1, v_in2 );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWU, VSHR, v_out, s_in1, v_in2 );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWU, VROTL, v_out, s_in1, v_in2 );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWU, VROTR, v_out, s_in1, v_in2 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SVWU, VCMV_LEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SVWU, VCMV_GTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SVWU, VCMV_LTZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SVWU, VCMV_GEZ, v_out, s_in1, v_in2 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SVWU, VCMV_Z, v_out, s_in1, v_in2 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SVWU, VCMV_NZ, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWU, VCUSTOM0, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWU, VCUSTOM1, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWU, VCUSTOM2, v_out, s_in1, v_in2 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWU, VCUSTOM3, v_out, s_in1, v_in2 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1 )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SVWU, VADD, v_out, s_in1, v_out );
		break;
	case VSUB:
		vbxasm_acc_3D( SVWU, VSUB, v_out, s_in1, v_out );
		break;
	case VADDC:
		vbxasm_acc_3D( SVWU, VADDC, v_out, s_in1, v_out );
		break;
	case VSUBB:
		vbxasm_acc_3D( SVWU, VSUBB, v_out, s_in1, v_out );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SVWU, VABSDIFF, v_out, s_in1, v_out );
		break;
	case VMUL:
		vbxasm_acc_3D( SVWU, VMUL, v_out, s_in1, v_out );
		break;
	case VMULHI:
		vbxasm_acc_3D( SVWU, VMULHI, v_out, s_in1, v_out );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SVWU, VMULFXP, v_out, s_in1, v_out );
		break;
	case VAND:
		vbxasm_acc_3D( SVWU, VAND, v_out, s_in1, v_out );
		break;
	case VOR:
		vbxasm_acc_3D( SVWU, VOR, v_out, s_in1, v_out );
		break;
	case VXOR:
		vbxasm_acc_3D( SVWU, VXOR, v_out, s_in1, v_out );
		break;
	case VSHL:
		vbxasm_acc_3D( SVWU, VSHL, v_out, s_in1, v_out );
		break;
	case VSHR:
		vbxasm_acc_3D( SVWU, VSHR, v_out, s_in1, v_out );
		break;
	case VROTL:
		vbxasm_acc_3D( SVWU, VROTL, v_out, s_in1, v_out );
		break;
	case VROTR:
		vbxasm_acc_3D( SVWU, VROTR, v_out, s_in1, v_out );
		break;
	case VMOV:
		vbxasm_acc_3D( SVWU, VMOV, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SVWU, VCUSTOM0, v_out, s_in1, v_out );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SVWU, VCUSTOM1, v_out, s_in1, v_out );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SVWU, VCUSTOM2, v_out, s_in1, v_out );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SVWU, VCUSTOM3, v_out, s_in1, v_out );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_byte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEB, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEB, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEB, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEB, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEB, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEB, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEB, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEB, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEB, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEB, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEB, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEB, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEB, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEB, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEB, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEB, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEB, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEB, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEB, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEB, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEB, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEB, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEB, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEB, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEB, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEB, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEB, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEB, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEB, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEB, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEB, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEB, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEB, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEB, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEB, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEB, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEB, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEB, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEB, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEB, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEB, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEB, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEB, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEB, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_ubyte_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEBU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEBU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEBU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEBU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEBU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEBU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEBU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEBU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEBU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEBU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEBU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEBU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEBU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEBU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEBU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEBU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEBU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEBU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEBU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEBU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEBU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEBU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEBU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEBU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEBU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEBU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEBU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEBU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEBU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEBU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEBU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEBU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEBU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEBU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEBU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEBU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEBU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEBU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEBU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEBU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEBU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEBU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEBU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEBU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_half_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEH, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEH, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEH, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEH, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEH, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEH, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEH, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEH, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEH, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEH, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEH, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEH, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEH, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEH, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEH, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEH, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEH, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEH, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEH, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEH, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEH, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEH, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEH, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEH, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEH, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEH, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEH, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEH, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEH, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEH, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEH, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEH, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEH, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEH, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEH, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEH, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEH, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEH, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEH, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEH, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEH, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEH, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEH, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEH, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uhalf_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEHU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEHU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEHU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEHU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEHU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEHU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEHU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEHU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEHU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEHU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEHU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEHU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEHU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEHU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEHU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEHU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEHU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEHU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEHU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEHU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEHU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEHU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEHU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEHU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEHU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEHU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEHU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEHU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEHU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEHU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEHU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEHU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEHU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEHU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEHU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEHU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEHU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEHU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEHU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEHU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEHU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEHU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEHU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEHU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEW, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEW, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEW, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEW, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEW, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEW, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEW, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEW, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEW, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEW, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEW, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEW, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEW, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEW, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEW, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEW, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEW, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEW, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEW, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEW, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEW, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEW, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEW, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEW, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEW, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEW, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEW, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEW, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEW, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEW, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEW, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEW, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEW, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEW, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEW, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEW, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEW, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEW, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEW, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEW, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEW, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEW, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEW, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEW, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t *v_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_in1),v_in1,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEWU, VADD, v_out, v_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEWU, VSUB, v_out, v_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEWU, VADDC, v_out, v_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEWU, VSUBB, v_out, v_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEWU, VABSDIFF, v_out, v_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEWU, VMUL, v_out, v_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEWU, VMULHI, v_out, v_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEWU, VMULFXP, v_out, v_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEWU, VAND, v_out, v_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEWU, VOR, v_out, v_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEWU, VXOR, v_out, v_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEWU, VSHL, v_out, v_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEWU, VSHR, v_out, v_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEWU, VROTL, v_out, v_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEWU, VROTR, v_out, v_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( VEWU, VCMV_LEZ, v_out, v_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( VEWU, VCMV_GTZ, v_out, v_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( VEWU, VCMV_LTZ, v_out, v_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( VEWU, VCMV_GEZ, v_out, v_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( VEWU, VCMV_Z, v_out, v_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( VEWU, VCMV_NZ, v_out, v_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEWU, VCUSTOM0, v_out, v_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEWU, VCUSTOM1, v_out, v_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEWU, VCUSTOM2, v_out, v_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEWU, VCUSTOM3, v_out, v_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,sizeof(*v_out),v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( VEWU, VADD, v_out, v_out, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( VEWU, VSUB, v_out, v_out, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( VEWU, VADDC, v_out, v_out, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( VEWU, VSUBB, v_out, v_out, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( VEWU, VABSDIFF, v_out, v_out, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( VEWU, VMUL, v_out, v_out, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( VEWU, VMULHI, v_out, v_out, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( VEWU, VMULFXP, v_out, v_out, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( VEWU, VAND, v_out, v_out, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( VEWU, VOR, v_out, v_out, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( VEWU, VXOR, v_out, v_out, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( VEWU, VSHL, v_out, v_out, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( VEWU, VSHR, v_out, v_out, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( VEWU, VROTL, v_out, v_out, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( VEWU, VROTR, v_out, v_out, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( VEWU, VCUSTOM0, v_out, v_out, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( VEWU, VCUSTOM1, v_out, v_out, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( VEWU, VCUSTOM2, v_out, v_out, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( VEWU, VCUSTOM3, v_out, v_out, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_byte_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEB, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEB, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEB, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEB, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEB, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEB, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEB, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEB, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEB, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEB, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEB, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEB, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEB, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEB, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEB, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEB, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEB, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEB, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEB, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEB, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEB, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEB, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEB, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEB, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEB, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_ubyte_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEBU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEBU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEBU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEBU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEBU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEBU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEBU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEBU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEBU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEBU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEBU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEBU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEBU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEBU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEBU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEBU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEBU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEBU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEBU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEBU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEBU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEBU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEBU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEBU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEBU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_half_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEH, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEH, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEH, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEH, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEH, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEH, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEH, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEH, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEH, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEH, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEH, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEH, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEH, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEH, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEH, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEH, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEH, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEH, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEH, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEH, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEH, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEH, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEH, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEH, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEH, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uhalf_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEHU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEHU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEHU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEHU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEHU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEHU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEHU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEHU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEHU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEHU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEHU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEHU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEHU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEHU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEHU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEHU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEHU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEHU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEHU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEHU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEHU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEHU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEHU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEHU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEHU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_word_t *v_out, vbx_word_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEW, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEW, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEW, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEW, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEW, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEW, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEW, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEW, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEW, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEW, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEW, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEW, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEW, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEW, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEW, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEW, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEW, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEW, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEW, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEW, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEW, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEW, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEW, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEW, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEW, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}

__attribute__((always_inline)) static inline void vbxx_acc_3D( vinstr_t v_op, vbx_uword_t *v_out, vbx_uword_t s_in1, vbx_enum_t *v_enum )
{
	vbx_acc_3D_chk(sizeof(*v_out),v_out,1,v_out,1,v_out,v_op);
	switch(v_op)
	{
	case VADD:
		vbxasm_acc_3D( SEWU, VADD, v_out, s_in1, 0 );
		break;
	case VSUB:
		vbxasm_acc_3D( SEWU, VSUB, v_out, s_in1, 0 );
		break;
	case VADDC:
		vbxasm_acc_3D( SEWU, VADDC, v_out, s_in1, 0 );
		break;
	case VSUBB:
		vbxasm_acc_3D( SEWU, VSUBB, v_out, s_in1, 0 );
		break;
	case VABSDIFF:
		vbxasm_acc_3D( SEWU, VABSDIFF, v_out, s_in1, 0 );
		break;
	case VMUL:
		vbxasm_acc_3D( SEWU, VMUL, v_out, s_in1, 0 );
		break;
	case VMULHI:
		vbxasm_acc_3D( SEWU, VMULHI, v_out, s_in1, 0 );
		break;
	case VMULFXP:
		vbxasm_acc_3D( SEWU, VMULFXP, v_out, s_in1, 0 );
		break;
	case VAND:
		vbxasm_acc_3D( SEWU, VAND, v_out, s_in1, 0 );
		break;
	case VOR:
		vbxasm_acc_3D( SEWU, VOR, v_out, s_in1, 0 );
		break;
	case VXOR:
		vbxasm_acc_3D( SEWU, VXOR, v_out, s_in1, 0 );
		break;
	case VSHL:
		vbxasm_acc_3D( SEWU, VSHL, v_out, s_in1, 0 );
		break;
	case VSHR:
		vbxasm_acc_3D( SEWU, VSHR, v_out, s_in1, 0 );
		break;
	case VROTL:
		vbxasm_acc_3D( SEWU, VROTL, v_out, s_in1, 0 );
		break;
	case VROTR:
		vbxasm_acc_3D( SEWU, VROTR, v_out, s_in1, 0 );
		break;
	case VCMV_LEZ:
		vbxasm_acc_3D( SEWU, VCMV_LEZ, v_out, s_in1, 0 );
		break;
	case VCMV_GTZ:
		vbxasm_acc_3D( SEWU, VCMV_GTZ, v_out, s_in1, 0 );
		break;
	case VCMV_LTZ:
		vbxasm_acc_3D( SEWU, VCMV_LTZ, v_out, s_in1, 0 );
		break;
	case VCMV_GEZ:
		vbxasm_acc_3D( SEWU, VCMV_GEZ, v_out, s_in1, 0 );
		break;
	case VCMV_Z:
		vbxasm_acc_3D( SEWU, VCMV_Z, v_out, s_in1, 0 );
		break;
	case VCMV_NZ:
		vbxasm_acc_3D( SEWU, VCMV_NZ, v_out, s_in1, 0 );
		break;
	case VCUSTOM0:
		vbxasm_acc_3D( SEWU, VCUSTOM0, v_out, s_in1, 0 );
		break;
	case VCUSTOM1:
		vbxasm_acc_3D( SEWU, VCUSTOM1, v_out, s_in1, 0 );
		break;
	case VCUSTOM2:
		vbxasm_acc_3D( SEWU, VCUSTOM2, v_out, s_in1, 0 );
		break;
	case VCUSTOM3:
		vbxasm_acc_3D( SEWU, VCUSTOM3, v_out, s_in1, 0 );
		break;
	default:
		break;
	}
}


#endif // __VBXX_HPP
