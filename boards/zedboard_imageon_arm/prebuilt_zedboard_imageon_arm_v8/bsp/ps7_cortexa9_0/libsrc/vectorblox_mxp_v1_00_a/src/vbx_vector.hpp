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


#ifndef __VECTOR_HPP
#define __VECTOR_HPP
#include "vbx.h"
namespace VBX{
	class fixed{};
namespace type_manipulation{
	template<typename T> class word_sized;
	template<>struct word_sized<vbx_word_t>{typedef vbx_word_t type;};
	template<>struct word_sized<vbx_half_t>{typedef vbx_word_t type;};
	template<>struct word_sized<vbx_byte_t>{typedef vbx_word_t type;};
	template<>struct word_sized<vbx_uword_t>{typedef vbx_uword_t type;};
	template<>struct word_sized<vbx_uhalf_t>{typedef vbx_uword_t type;};
	template<>struct word_sized<vbx_ubyte_t>{typedef vbx_uword_t type;};
	template<>struct word_sized<fixed>{typedef vbx_word_t type;};
	template<typename T> struct convert_to_unsigned{typedef T type;};
	template<>struct convert_to_unsigned<vbx_word_t>{typedef vbx_uword_t type;};
	template<>struct convert_to_unsigned<vbx_half_t>{typedef vbx_uhalf_t type;};
	template<>struct convert_to_unsigned<vbx_byte_t>{typedef vbx_ubyte_t type;};
	template<typename T> struct convert_to_signed{typedef T type;};
	template<>struct convert_to_signed<vbx_uword_t>{typedef vbx_word_t type;};
	template<>struct convert_to_signed<vbx_uhalf_t>{typedef vbx_half_t type;};
	template<>struct convert_to_signed<vbx_ubyte_t>{typedef vbx_byte_t type;};

	template<typename T> struct representation{typedef T type;};
	template<> struct representation<fixed>{typedef vbx_word_t type;};
#define repr( typ ) typename type_manipulation::representation<typ>::type
}
inline int vector_length()
{
	int vl;
	vbx_get_vl(&vl);
	return vl;
}

inline void set_vl(int vl)
{
	vbx_set_vl(vl);
}
template<typename T>
class ENUM{};
template<typename T>
class Offset;
template<typename T>
class Vector_Op{
	typedef typename type_manipulation::word_sized<T>::type word_T;
public:
	//these memebers must be public for annoying reasons
	//see http://stackoverflow.com/q/16785069/1166209
	const Vector_Op *child_L,*child_R;
	bool needs_temp;
	vinstr_t cmv;
	virtual repr(T)* resolve(repr(T)* temp)const{return NULL;}
	explicit Vector_Op():needs_temp(true),cmv(VCMV_NZ){}
	Vector_Op(const Vector_Op *child_L,const Vector_Op *child_R):
		child_L(child_L),child_R(child_R),needs_temp(true),cmv(VCMV_NZ){}
	Offset<T> operator[](int offset);
	virtual ~Vector_Op(){}
};

template<typename T>
class Vector: public Vector_Op<T>{
private:
	typedef typename type_manipulation::word_sized<T>::type scalar_type;
	//scalar_type scalar;
protected:
	repr(T)* data;
	int size;
	Vector(){}
public:
	virtual repr(T)* resolve(repr(T)* temp)const;
	explicit Vector(int size);
	Vector(const Vector& copy);
	virtual ~Vector();
	Vector & operator=(const Vector_Op<T>& rhs);
	Vector & operator=(const Vector& rhs);
	Vector & operator=(scalar_type rhs);
	//
	Vector & cond_move(const Vector_Op<T>& predicate,const Vector_Op<T>& rhs);
	Vector & cond_move(const Vector_Op<T>& predicate,scalar_type rhs);
	//compound assignments
	Vector & operator+=(const Vector_Op<T>& rhs){return *this = *this + rhs;};
	Vector & operator-=(const Vector_Op<T>& rhs){return *this = *this - rhs;};
	Vector & operator*=(const Vector_Op<T>& rhs){return *this = *this * rhs;};
	Vector & operator^=(const Vector_Op<T>& rhs){return *this = *this ^ rhs;};
	Vector & operator|=(const Vector_Op<T>& rhs){return *this = *this | rhs;};
	Vector & operator&=(const Vector_Op<T>& rhs){return *this = *this & rhs;};
	Vector & operator<<=(const Vector_Op<T>& rhs){return *this = *this << rhs;};
	Vector & operator>>=(const Vector_Op<T>& rhs){return *this = *this >> rhs;};
	Vector & operator+=( vbx_word_t rhs){return *this = *this + rhs;};
	Vector & operator-=( vbx_word_t rhs){return *this = *this - rhs;};
	Vector & operator*=( vbx_word_t rhs){return *this = *this * rhs;};
	Vector & operator^=( vbx_word_t rhs){return *this = *this ^ rhs;};
	Vector & operator|=( vbx_word_t rhs){return *this = *this | rhs;};
	Vector & operator&=( vbx_word_t rhs){return *this = *this & rhs;};
	Vector & operator<<=(vbx_word_t rhs){return *this = *this << rhs;};
	Vector & operator>>=(vbx_word_t rhs){return *this = *this >> rhs;};

	repr(T)* get_sp_ptr()const{return data;}
	int  get_size()const{return size;}
	void get_data(T* to)const{vbx_dma_to_host(to,data,this->size*sizeof(T));}
	void set_data(T* from){vbx_dma_to_vector(data,from,this->size*sizeof(T));}
	void printVec(int n=-1) const;
};

template<typename T>
class Offset: public Vector<T>{
private:
	typedef typename type_manipulation::word_sized<T>::type scalar_type;
	int offset;
public:
	explicit Offset(Vector_Op<T>* child,int offset)
		:offset(offset)
	{
		this->child_L=child;
		this->needs_temp=false;
	}
	~Offset()
	{vbx_sp_push();}//~Vector() will undo this push

	virtual repr(T)* resolve(repr(T)* temp)const
	{
		if(temp==NULL){//return pointer
			if(this->child_L->needs_temp){
				temp=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
			}
			temp=this->child_L->resolve(temp)+offset;
		}else{//move into temp
			if(this->child_L->needs_temp){
				temp=this->child_L->resolve(temp);
			}else{
				vbxx(VMOV,temp,this->child_L->resolve(NULL));
			}
		}
		return temp;
	}
	Offset & operator=(const Vector_Op<T>& rhs){Vector<T>::operator=(rhs);return *this;}
	Offset & operator=(const Vector<T>& rhs)   {Vector<T>::operator=(rhs);return *this;}
	Offset & operator=(const Offset& rhs)      {Vector<T>::operator=(rhs);return *this;}
	Offset & operator=(scalar_type rhs)        {Vector<T>::operator=(rhs);return *this;}
};

template<typename T>
Offset<T> Vector_Op<T>::operator[](int offset)
{
	return Offset<T>(this,offset);
}
template<typename T>
repr(T)* Vector<T>::resolve(repr(T)* tmp) const
{
	if (tmp==NULL){
		return this->data;
	}else{//move into tmp
		vbxx(VMOV,tmp,this->data);
		return tmp;
	}
}
template<typename T>
void Vector<T>::printVec(int n) const
{
	int sz;
	if (n!=-1){
		sz=min(n,get_size());
	}else{
		sz=get_size();
	}
	T* v=(T*)malloc(sizeof(T)*sz);
	vbx_dma_to_host(v,this->resolve(NULL),sizeof(T)*sz);
	vbx_sync();
	for(int i=0;i<sz;i++){
		printf("[%d]=%d\n", i,v[i]);
	}
	free(v);
}

template<typename T>
Vector<T>::Vector(int size):
	Vector_Op<T>()
{
	this->needs_temp=false;
	this->size=size;
	vbx_sp_push();
	data=(repr(T)*)vbx_sp_malloc(this->size*sizeof(repr(T)));
}
template<typename T>
Vector<T>::Vector(const Vector& copy):
	Vector_Op<T>()
{
	vbx_sp_push();
	this->size=copy.size;
	data=(repr(T)*)vbx_sp_malloc(this->size*sizeof(repr(T)));
	copy.resolve(data);
	this->needs_temp=false;
}
template <typename T>
Vector<T>::~Vector<T>()
{
	vbx_sp_pop();
}
template <typename T>
Vector<T> & Vector<T>::operator=(const Vector_Op<T>& rhs)
{
	vbx_sp_push();
	rhs.resolve(this->resolve(NULL));
	vbx_sp_pop();
	return *this;
}
template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T>& rhs)
{
	vbx_sp_push();
	rhs.resolve(this->resolve(NULL));
	vbx_sp_pop();
	return *this;
}
template <typename T>
Vector<T> & Vector<T>::operator=(scalar_type rhs)
{
	vbx_sp_push();
	vbxx(VMOV,this->resolve(NULL),rhs);
	vbx_sp_pop();
	return *this;
}
template<typename T>
Vector<T>& Vector<T>::cond_move(const Vector_Op<T>& predicate,const Vector_Op<T>& data)
{
	vbx_sp_push();
	T *d=NULL,*p=NULL;
	if(predicate.needs_temp){
		p=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
	}
	if (data.needs_temp){
		d=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
	}
	vbxx(predicate.cmv,this->resolve(NULL),data.resolve(d),predicate.resolve(p));
	vbx_sp_pop();
   return *this;
}
template<typename T>
Vector<T>& Vector<T>::cond_move(const Vector_Op<T>& predicate,Vector<T>::scalar_type data)
{
	vbx_sp_push();
	repr(T)* p=NULL;
	if (predicate.needs_temp){
		p=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
	}
	vbxx(predicate.cmv,this->resolve(NULL),data,predicate.resolve(p));
	vbx_sp_pop();
	return *this;
}

template<typename T>
class VV_OP:public Vector_Op<T>
{
	vinstr_t instr;
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		repr(T)* srcL=NULL;
      if (this->child_L->needs_temp)
	      srcL=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcL=this->child_L->resolve(srcL);
      repr(T)* srcR=NULL;
      if (this->child_R->needs_temp)
	      srcR=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcR=this->child_R->resolve(srcR);
      vbxx(this->instr,dest,srcL,srcR);
      return dest;
	}
	VV_OP(const Vector_Op<T>* lhs, const Vector_Op<T>* rhs,vinstr_t instr)
		:Vector_Op<T>(lhs,rhs),instr(instr)
	{}
};
template<typename T>
class SV_OP:public Vector_Op<T>
{
	typename type_manipulation::word_sized<T>::type scalar;
	vinstr_t instr;
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		repr(T)* srcR=NULL;
      if (this->child_R->needs_temp)
	      srcR=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcR=this->child_R->resolve(srcR);
      vbxx(this->instr,dest,scalar,srcR);
      return dest;
	}
	SV_OP(typename type_manipulation::word_sized<T>::type s, const Vector_Op<T>* rhs,vinstr_t instr)
		:Vector_Op<T>(NULL,rhs),scalar(s),instr(instr)
	{}
};
template<typename T>
class VE_OP:public Vector_Op<T>
{
	vinstr_t instr;
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		vbx_enum_t* srcR=NULL;
		repr(T)* srcL=NULL;
      if (this->child_L->needs_temp)
	      srcL=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcL=this->child_L->resolve(srcL);
      vbxx(this->instr,dest,srcL,srcR);
      return dest;
	}
	VE_OP(const Vector_Op<T>* lhs,vinstr_t instr)
		:Vector_Op<T>(lhs,NULL),instr(instr)
	{}
};
template<typename T>
class SE_OP:public Vector_Op<T>
{
	typename type_manipulation::word_sized<T>::type scalar;
	vinstr_t instr;
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		vbx_enum_t* srcR=NULL;
      vbxx(this->instr,dest,scalar,srcR);
      return dest;
	}
	SE_OP(typename type_manipulation::word_sized<T>::type s,vinstr_t instr)
		:Vector_Op<T>(NULL,NULL),scalar(s),instr(instr)
	{}
};
template<typename T>
class COMP_VV_OP:public Vector_Op<T>{
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		repr(T)* srcL=NULL;
      if (this->child_L->needs_temp)
	      srcL=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcL=this->child_L->resolve(srcL);
      repr(T)* srcR=NULL;
      if (this->child_R->needs_temp)
	      srcR=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcR=this->child_R->resolve(srcR);
      vbxx(VSUB,dest,srcL,srcR);
      return dest;
	}
	COMP_VV_OP(const Vector_Op<T>*lhs,const Vector_Op<T>*rhs,vinstr_t cmv_instr)
		:Vector_Op<T>(lhs,rhs)
	{
		this->cmv=cmv_instr;
	}
};
template<typename T>
class COMP_SV_OP:public Vector_Op<T>{
	typename type_manipulation::word_sized<T>::type scalar;
public:
	virtual repr(T)* resolve(repr(T)* dest) const
	{
		repr(T)* srcR=NULL;
      if (this->child_R->needs_temp)
	      srcR=(repr(T)*)vbx_sp_malloc(vector_length()*sizeof(repr(T)));
      srcR=this->child_R->resolve(srcR);
      if(scalar== 0 and (this->cmv == VCMV_Z || this->cmv == VCMV_NZ)){
	      //skip the subtraction if checking equality with zero, it isn't necessary
	      dest=srcR;
      }else{
	      vbxx(VSUB,dest,scalar,srcR);
      }
      return dest;
	}
	COMP_SV_OP(typename type_manipulation::word_sized<T>::type scalar,const Vector_Op<T>*rhs,vinstr_t cmv_instr)
		:Vector_Op<T>(NULL,rhs),scalar(scalar)
	{
		this->cmv=cmv_instr;
	}
};


#include "vbx_operators.hpp"
struct Parameter{
	void* ptr;
	Parameter* next;
	template<typename T>
	Parameter operator ,(VBX::Vector<T>& p)
	{
		Parameter ret;
		ret.next=this;
		ret.ptr=p.get_sp_ptr();
		return ret;
	}
};

#define PARAM( ... ) (*((VBX::Parameter*)NULL) , __VA_ARGS__ )
}//namespace VBX

#endif //__jit_hpp
