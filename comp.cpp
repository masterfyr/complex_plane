#include "comp.h"

//default constructor
comp::comp():re(0),im(0){}

//nondefault constructor
comp::comp(_c_type_ _re, _c_type_ _im): re(_re),im(_im){}

//constructor from real value
comp::comp(_c_type_ _re): re(_re), im(0){}

//constructor from polar coordinates
comp::comp(_c_type_ rho, _c_type_ phi, int): re(rho*cos(phi)), im(rho*sin(phi))
{
    if (rho<0) throw NONPOSITIVE_MODUL;
}

//setter
inline void comp::set(_c_type_ _re, _c_type_ _im)
{
    re=_re;
    im=_im;
}

//the norm of the number
inline _c_type_ comp::norm(void) const
{
    return sqr(re)+sqr(im);
}

//distanse to the zero
inline _c_type_ comp::modul(void) const
{
    return sqrt(norm());
}

//angle
inline _c_type_ comp::phi(void) const
{
    if ((im==0)&&(re==0)) return 0;
    _c_type_ t=acos(re/modul());
    if (im>=0) return t;
    return 2*M_PI - t;
}

//addition of two complex numbers
inline comp comp::add(const comp& op) const
{
    comp res(re + op.re, im + op.im);
    return res;
}

//multiplication of two complex numbers
inline comp comp::mult(const comp& op) const
{
    comp res(re*op.re - im*op.im, im*op.re + op.im*re);
    return res;
}

//multiplication by a real constant
inline comp comp::mult(_c_type_ op_re) const
{
    comp res(re*op_re, im*op_re);
    return res;
}

//conjugation
inline comp comp::conj(void) const
{
    comp res(re,-im);
    return res;
}

//equality
inline int comp::eqauls(const comp& op) const
{
    return ((re==op.re)&&(im==op.im));
}
//equality
inline int comp::eqauls(_c_type_ op_re) const
{
    return ((re==op_re)&&(im==0));
}

/**
      * computes the complex inverse
      * @return inverse comp
      * @throws UNINVERTABLE exception
      */
inline comp comp::inv(void) const
{
    _c_type_ t=norm();
    if (t==0) throw UNINVERTABLE;
    return conj().mult(1/norm());
}

//divide
inline comp comp::div(comp const& op) const
{
    return mult(op.inv());
}

inline comp comp::meb_trans(const comp& a , const comp& b , const comp& c , const comp& d) const
{
    comp res=this->mult(a).add(b);
    res = res.div(this->mult(c).add(d));
    return res;
}

//square
inline comp comp::sqr_c(void) const
{
    return this->mult(*this);
}

//power
inline comp comp::cpow(_c_type_ arg) const
{
    return comp(pow(this->modul() , arg) , this->phi()*arg , 0);
}

//natural logarithm
inline comp comp::ln(void) const
{
    if (this->eqauls(0)) throw ZERO_LN_ARG;
    return comp(log(this->modul())/log( M_E ) , this->phi());
}

//exp
inline comp comp::cexp(void) const
{
    return comp( exp(re) , im  , 0);
}

//error message
char* comp::err_msg(int i)
{
    if (i==UNINVERTABLE) return (char*)"Uninvertible matrix";
    else return (char*)"No Errors";
}

//distance in R_2 metrics of two points
_c_type_ comp::dist(const comp& op1, const comp& op2)
{
    return (op1.add(op2.mult(-1))).modul();
}

//operator of equality
int comp::operator== (const comp& op1) const
{
    return this->eqauls(op1);
}

//operator of the addition
comp comp::operator+(const comp& op1) const
{
    return this->add(op1);
}

//operator of the multiplication
comp comp::operator*(const comp& op1) const
{
    return this->mult(op1);
}

//operator: power of the num
comp comp::operator^(_c_type_ op1) const
{
    return this->cpow(op1);
}

//operator difference
comp comp::operator-(const comp& op) const
{
    return this->add(op.mult(-1));
}



