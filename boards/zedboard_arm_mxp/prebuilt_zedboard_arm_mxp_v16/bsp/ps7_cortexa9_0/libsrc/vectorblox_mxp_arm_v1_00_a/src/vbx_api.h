/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2013 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
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

/**
 * @defgroup VBXapi
 * @brief VBX API library
 */
/**
 * @file
 * @defgroup VBX_API
 * @brief VBX API
 *
 * @ingroup VBXapi
 */
/**@{*/

#ifndef __VBX_API_H
#define __VBX_API_H

#ifdef __cplusplus
extern "C" {
#endif
// -----------------------------------------------------------
// DEVELOPER API SECTION
// -----------------------------------------------------------

void        _vbx_init( vbx_mxp_t *this_mxp );

// Scratchpad APIs

vbx_void_t *vbx_sp_malloc_nodebug(                      size_t num_bytes );
vbx_void_t *vbx_sp_malloc_debug( int LINE, char *FNAME, size_t num_bytes );

void        vbx_sp_free_debug( int LINE, char *FNAME );
void        vbx_sp_free_nodebug();

vbx_void_t *vbx_sp_get();

void        vbx_sp_set_nodebug(                      vbx_void_t *new_sp );
void        vbx_sp_set_debug( int LINE, char *FNAME, vbx_void_t *new_sp );

int         vbx_sp_getused();
int         vbx_sp_getfree();

void        vbx_sp_push_nodebug();
void        vbx_sp_push_debug( int LINE, char *FNAME );

void        vbx_sp_pop_nodebug();
void        vbx_sp_pop_debug( int LINE, char *FNAME );

// Memory APIs

void       *vbx_shared_alloca_nodebug( size_t num_bytes, void *p );
void       *vbx_shared_alloca_debug( int LINE, char *FNAME, size_t num_bytes, void *p );
void       *vbx_shared_malloc( size_t num_bytes );
void        vbx_shared_free( void *shared_ptr );

// MXP device APIs
vbx_mxp_t  *vbx_open( const char* name );

#ifdef __cplusplus
}
#endif

#endif // __VBX_API_H
/**@}*/
