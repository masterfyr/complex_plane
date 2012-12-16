#ifndef _COMP_H_
#define _COMP_H_

//define basic math constants
#define _USE_MATH_DEFINES
#undef _MATH_DEFINES_DEFINED

//include math arithmetics

#include "math.h"

//define the specific type of real part of
//the complex numbers

#define _c_type double

//define the square function
#define sqr(x) ((x)*(x)) 

#define comp_r(x) (_c_get_r(x))
#define comp_s( x , y ) (_c_get_s((x),(y)))

//complex number
struct _c_struct
{
    //real part of the complex number
    _c_type re;

    //imaginary part of the real number
    _c_type im;
};
typedef struct _c_struct comp;

//exceptions
enum _c_exception
{
    NO_EXCEPTION,
    UNINVERTABLE,
    NONPOSITIVE_MODUL,
    ZERO_LN_ARG
};

//imaginary unity
const comp C_I={ 0, 1};

//complex zero
const comp C_ZERO={0,0};

//nondefault constructor
inline comp _c_get_s(_c_type _re, _c_type _im)
{
   comp res={_re,_im};
   return res;
}

//constructor from real value
inline comp _c_get_r(_c_type _re)
{
    comp res={_re,0};
    return res;
}

//constructor from polar coordinates
inline _c_exception _c_get_pol(_c_type rho, _c_type phi, comp& res)
{
    if (rho<0) return NONPOSITIVE_MODUL;
    res.re=rho*cos(phi);
    res.im=rho*sin(phi);
    return NO_EXCEPTION;
}

//equality
inline int _c_eqauls(const comp& op1,const comp& op2)
{
    return ((op1.re==op2.re)&&(op1.im==op2.im));
}

//the norm of the number
inline _c_type _c_norm(const comp& op)
{
    return sqr(op.re)+sqr(op.im);
}

//distanse to the zero
inline _c_type _c_modul(const comp& op)
{
    return sqrt(_c_norm(op));
}

//angle
inline _c_type _c_phi(const comp& op)
{
    if (_c_eqauls(op,C_ZERO)) return 0;
    _c_type t=acos(op.re/_c_modul(op));
    if (op.im>=0) return t;
    return 2*M_PI - t;
}

//addition of two complex numbers
inline comp _c_add(const comp& op1, const comp& op2)
{
    comp res={op1.re + op2.re, op1.im + op2.im};
    return res;
}

//multiplication of two complex numbers
inline comp _c_mult(const comp& op1, const comp& op2)
{
    comp res={op1.re*op2.re - op1.im*op2.im, op1.im*op2.re + op2.im*op1.re};
    return res;
}

//conjugation
inline comp _c_conj(const comp& op)
{
    comp res={op.re,-op.im};
    return res;
}

//computes the complex inverse
inline _c_exception _c_inv(const comp& op, comp& res)
{
    _c_type t=_c_norm(op);
    if (t==0) return UNINVERTABLE;
    res=_c_mult(_c_conj(op),comp_r(1/_c_norm(op)));
    return NO_EXCEPTION;
}

//divide
inline _c_exception _c_div(comp const& op1, const comp& op2, comp& res)
{
    comp t;
    _c_exception exc=_c_inv(op2,t);
    if (exc!=NO_EXCEPTION) return exc;
    res=_c_mult(op1,t);
    return NO_EXCEPTION;
}

inline _c_exception _c_meb_trans(const comp& a , const comp& b , const comp& c , const comp& d, const comp& op, comp& res)
{
    res=_c_add(_c_mult(op,a),b);
    return _c_div(res,_c_add(_c_mult(op,c),d),res);
}

//square
inline comp _c_sqr(const comp& op)
{
    return _c_mult(op,op);
}

//power
inline comp _c_pow(const comp& op , _c_type arg)
{
    comp res;
    _c_get_pol(pow(_c_modul(op) , arg) , _c_phi(op)*arg, res);
    return res;
}

//natural logarithm
inline _c_exception _c_ln(const comp& op, comp& res)
{
    if (_c_eqauls(op,C_ZERO)) return ZERO_LN_ARG;
    res=comp_s(log(_c_modul(op))/log( M_E ) , _c_phi(op));
    return NO_EXCEPTION;
}

//exp
inline comp _c_exp(const comp& op)
{
    comp res;
    _c_get_pol(exp(op.re) , op.im , res);
    return res;
}

//error message
inline char* _c_err_msg(_c_exception exc)
{
    if (exc==UNINVERTABLE) return (char*)"Uninvertible matrix";
    else return (char*)"No Errors";
}

//distance in R_2 metrics of two points
inline _c_type _c_dist(const comp& op1, const comp& op2)
{
    return _c_modul(_c_add(op1, _c_mult(op2,comp_r(-1))));
}
#endif // COMP_H
