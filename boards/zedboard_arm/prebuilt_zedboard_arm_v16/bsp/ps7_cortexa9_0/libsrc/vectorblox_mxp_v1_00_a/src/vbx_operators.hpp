#define VV_OPERATOR(inst,op)\
	template<typename T> \
	VV_OP<T> operator op (const Vector_Op<T>& lhs, const Vector_Op<T>& rhs) \
	{ \
		return VV_OP<T>(&lhs,&rhs,inst); \
	}

#define SV_OPERATOR(instr,op)\
	template<typename T> \
	SV_OP<T> operator op (typename type_manipulation::word_sized<T>::type scalar, const Vector_Op<T>& rhs) \
	{ \
		return SV_OP<T>(scalar,&rhs,instr); \
	}
#define VS_OPERATOR(instr,op)	  \
	template<typename T> \
	SV_OP<T> operator op (const Vector_Op<T>& lhs,typename type_manipulation::word_sized<T>::type scalar) \
	{ \
		return SV_OP<T>(scalar,&lhs,instr); \
	}
#define VE_OPERATOR(instr,op)	  \
	template<typename T> \
	VE_OP<T> operator op (const Vector_Op<T>& lhs, ENUM<T> rhs) \
	{ \
		return VE_OP<T>(&lhs, instr ); \
	}
#define EV_OPERATOR(instr,op)	  \
	template<typename T> \
	VE_OP<T> operator op ( ENUM<T> lhs, const Vector_Op<T>& rhs) \
	{ \
		return VE_OP<T>(&rhs, instr ); \
	}
#define SE_OPERATOR(instr,op)	  \
	template<typename T> \
	SE_OP<T> operator op (typename type_manipulation::word_sized<T>::type lhs, ENUM<T> rhs) \
	{ \
		return SE_OP<T>(lhs, instr ); \
	}
#define ES_OPERATOR(instr,op)	  \
	template<typename T> \
	SE_OP<T> operator op ( ENUM<T> lhs,typename type_manipulation::word_sized<T>::type rhs) \
	{ \
		return SE_OP<T>(rhs, instr ); \
	}
#define COMP_OP_VV(instr,op)	  \
	template<typename T> \
	COMP_VV_OP<T> operator op (const Vector_Op<T>& lhs, const Vector_Op<T> &rhs)\
	{\
		return COMP_VV_OP<T>(&lhs, &rhs, instr); \
	}
#define COMP_OP_SV( instr,op )	  \
	template<typename T> \
	COMP_SV_OP<T> operator op (typename type_manipulation::word_sized<T>::type scalar, const Vector_Op<T> &rhs) \
	{ \
		return COMP_SV_OP<T>(scalar, &rhs, instr); \
	}
#define COMP_OP_VS( instr,op )	  \
	template<typename T> \
	COMP_SV_OP<T> operator op (const Vector_Op<T> &lhs, typename type_manipulation::word_sized<T>::type scalar) \
	{ \
		return COMP_SV_OP<T>(scalar, &lhs, instr); \
	}


VV_OPERATOR(VADD,+)
VV_OPERATOR(VSUB,-)
VV_OPERATOR(VMUL,*)
VV_OPERATOR(VAND,&)
VV_OPERATOR( VOR,|)
VV_OPERATOR(VXOR,^)
//VV_OPERATOR(VSHL,<<)//these operands have their order switched around
//VV_OPERATOR(VSHR,>>)//these operands have their order switched around
SV_OPERATOR(VADD,+)
SV_OPERATOR(VSUB,-)
SV_OPERATOR(VMUL,*)
SV_OPERATOR(VAND,&)
SV_OPERATOR( VOR,|)
SV_OPERATOR(VXOR,^)
//SV_OPERATOR(VSHR,<<)
//SV_OPERATOR(VSHL,>>)
VS_OPERATOR(VADD,+)
//VS_OPERATOR(VSUB,-)
VS_OPERATOR(VMUL,*)
VS_OPERATOR(VAND,&)
VS_OPERATOR(VOR,|)
VS_OPERATOR(VXOR,^)
//VS_OPERATOR(VSHR,<<)
//VS_OPERATOR(VSHL,>>)

COMP_OP_VV(VCMV_LTZ,< )
COMP_OP_VV(VCMV_GTZ,> )
COMP_OP_VV(VCMV_LEZ,<=)
COMP_OP_VV(VCMV_GEZ,>=)
COMP_OP_VV(VCMV_Z  ,==)
COMP_OP_VV(VCMV_NZ ,!=)
COMP_OP_SV(VCMV_LTZ,< )
COMP_OP_SV(VCMV_GTZ,> )
COMP_OP_SV(VCMV_LEZ,<=)
COMP_OP_SV(VCMV_GEZ,>=)
COMP_OP_SV(VCMV_Z  ,==)
COMP_OP_SV(VCMV_NZ ,!=)
COMP_OP_VS(VCMV_GTZ,< )
COMP_OP_VS(VCMV_LTZ,> )
COMP_OP_VS(VCMV_GEZ,<=)
COMP_OP_VS(VCMV_LEZ,>=)
COMP_OP_VS(VCMV_Z  ,==)
COMP_OP_VS(VCMV_NZ ,!=)

VE_OPERATOR(VADD,+)
VE_OPERATOR(VSUB,-)
VE_OPERATOR(VMUL,*)
VE_OPERATOR(VAND,&)
VE_OPERATOR( VOR,|)
VE_OPERATOR(VXOR,^)
//VE_OPERATOR(VSHR,<<)
//VE_OPERATOR(VSHL,>>)
EV_OPERATOR(VADD,+)
//EV_OPERATOR(VSUB_I,-)
EV_OPERATOR(VMUL,*)
EV_OPERATOR(VAND,&)
EV_OPERATOR( VOR,|)
EV_OPERATOR(VXOR,^)
//EV_OPERATOR(VSHR_I,<<)
//EV_OPERATOR(VSHL_I,>>)
SE_OPERATOR(VADD,+)
SE_OPERATOR(VSUB,-)
SE_OPERATOR(VMUL,*)
SE_OPERATOR(VAND,&)
SE_OPERATOR( VOR,|)
SE_OPERATOR(VXOR,^)
//SE_OPERATOR(VSHR,<<)
//SE_OPERATOR(VSHL,>>)
ES_OPERATOR(VADD,+)
//ES_OPERATOR(VSUB,-)
ES_OPERATOR(VMUL,*)
ES_OPERATOR(VAND,&)
ES_OPERATOR( VOR,|)
ES_OPERATOR(VXOR,^)
//ES_OPERATOR(VSHR_I,<<)
//ES_OPERATOR(VSHL_I,>>)

/**
 * subraction is not commutative, so we need to define the SV different from VS
 */
template<typename T>
SV_OP<T> operator-( const Vector_Op<T>& lhs,typename type_manipulation::word_sized<T>::type scalar)
{
	return SV_OP<T>(-scalar,&lhs,VADD);
}
template<typename T>
SE_OP<T> operator-( ENUM<T> lhs,typename type_manipulation::word_sized<T>::type rhs)
{
	return SE_OP<T>(-rhs,VADD);
}
/**
 * the mxp defines vbxx(VSHL,d,a,b) as shifting b left by a bits,
 * the c language defines a<<b      as shifting a left by b bits.
 * because of this we have to define all of the shifting operations manually
 */
//VS Shift
template<typename T>
SV_OP<T> operator << (const Vector_Op<T>& lhs,typename type_manipulation::word_sized<T>::type scalar )
{
	return SV_OP<T>(scalar,&lhs,VSHL);
}
template<typename T>
SV_OP<T> operator >> (const Vector_Op<T>& lhs,typename type_manipulation::word_sized<T>::type scalar )
{
	return SV_OP<T>(scalar,&lhs,VSHR);
}
//VV shift
template<typename T>
VV_OP<T> operator << (const Vector_Op<T>& lhs, const Vector_Op<T>& rhs)
{
	return VV_OP<T>(&rhs,&lhs,VSHL);
}

template<typename T>
VV_OP<T> operator >> (const Vector_Op<T>& lhs, const Vector_Op<T>& rhs)
{
	return VV_OP<T>(&rhs,&lhs,VSHR);
}
//EV shift
template<typename T>
VE_OP<T> operator << ( ENUM<T> lhs,const Vector_Op<T>& rhs)
{
	return VE_OP<T>(&rhs,VSHL);
}
template<typename T>
VE_OP<T> operator >> ( ENUM<T> lhs,const Vector_Op<T>& rhs)
{
	return VE_OP<T>(&rhs,VSHR);
}
//ES shift
template<typename T>
SE_OP<T> operator << ( ENUM<T> lhs,typename type_manipulation::word_sized<T>::type scalar)
{
	return SE_OP<T>(scalar,VSHL);
}
template<typename T>
SE_OP<T> operator >> ( ENUM<T> lhs,typename type_manipulation::word_sized<T>::type scalar)
{
	return SE_OP<T>(scalar,VSHR);
}

/**
 * Multiplication is different for fixed point, so we make dedicated functions for that
 */
VV_OP<fixed> inline operator * (const Vector_Op<fixed>& lhs, const Vector_Op<fixed>& rhs)
{
	return VV_OP<fixed>(&lhs,&rhs,VMULFXP);
}
SV_OP<fixed> inline operator * ( type_manipulation::word_sized<fixed>::type scalar, const Vector_Op<fixed>& rhs)
{
	return SV_OP<fixed>(scalar,&rhs,VMULFXP);
}
SV_OP<fixed> inline operator * (const Vector_Op<fixed>& lhs, type_manipulation::word_sized<fixed>::type scalar)
{
	return SV_OP<fixed>(scalar,&lhs,VMULFXP);
}
VE_OP<fixed> inline operator * (const Vector_Op<fixed>& lhs, ENUM<fixed> rhs)
{
	return VE_OP<fixed>(&lhs, VMULFXP );
}
VE_OP<fixed> inline operator * ( ENUM<fixed> lhs, const Vector_Op<fixed>& rhs)
{
	return VE_OP<fixed>(&rhs, VMULFXP );
}
SE_OP<fixed> inline operator * ( type_manipulation::word_sized<fixed>::type lhs, ENUM<fixed> rhs) \
{
	return SE_OP<fixed>(lhs, VMUL );
}
SE_OP<fixed> inline operator * ( ENUM<fixed> lhs, type_manipulation::word_sized<fixed>::type rhs) \
{
	return SE_OP<fixed>(rhs, VMUL );
}

#undef VV_OPERATOR
#undef SV_OPERATOR
#undef VS_OPERATOR
#undef COMP_OP_VV
#undef COMP_OP_SV
#undef COMP_OP_VS
#undef VE_OPERATOR
#undef VE_OPERATOR
#undef EV_OPERATOR
#undef SE_OPERATOR
#undef ES_OPERATOR
