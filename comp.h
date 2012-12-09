#ifndef COMP_H
#define COMP_H


#define _USE_MATH_DEFINES
#undef _MATH_DEFINES_DEFINED
#include "math.h"

#define _c_type_ double

#define sqr(x) ((x)*(x))

class comp
{
public:

    static const int UNINVERTABLE = 1;
    static const int NONPOSITIVE_MODUL = 2;
    static const int ZERO_LN_ARG = 3;

#define COMP_I (comp(0,1))
#define COMP_ZERO (comp(0,0))

    //real part of the complex number
    double re;

    //imaginary part of the real number
    double im;

    //default constructor
    comp():re(0),im(0){}

    //nondefault constructor
    comp(_c_type_ _re, _c_type_ _im): re(_re),im(_im){}

    //constructor from real value
    comp(_c_type_ _re): re(_re), im(0){}

    //constructor from polar coordinates
    comp(_c_type_ rho, _c_type_ phi, int): re(rho*cos(phi)), im(rho*sin(phi))
    {
        if (rho<0) throw NONPOSITIVE_MODUL;
    }

    //setter
    inline void set(_c_type_ _re, _c_type_ _im)
    {
        re=_re;
        im=_im;
    }

    //the norm of the number
    inline _c_type_ norm(void) const
    {
        return sqr(re)+sqr(im);
    }

    //distanse to the zero
    inline _c_type_ modul(void) const
    {
        return sqrt(norm());
    }

    //angle
    inline _c_type_ phi(void) const
    {
        if ((im==0)&&(re==0)) return 0;
        _c_type_ t=acos(re/modul());
        if (im>=0) return t;
        return 2*M_PI - t;
    }

    //addition of two complex numbers
    inline comp add(const comp& op) const
    {
        comp res(re + op.re, im + op.im);
        return res;
    }

    //multiplication of two complex numbers
    inline comp mult(const comp& op) const
    {
        comp res(re*op.re - im*op.im, im*op.re + op.im*re);
        return res;
    }

    //multiplication by a real constant
    inline comp mult(_c_type_ op_re) const
    {
        comp res(re*op_re, im*op_re);
        return res;
    }

    //conjugation
    inline comp conj(void) const
    {
        comp res(re,-im);
        return res;
    }

    //equality
    inline int eqauls(const comp& op) const
    {
        return ((re==op.re)&&(im==op.im));
    }
    //equality
    inline int eqauls(_c_type_ op_re) const
    {
        return ((re==op_re)&&(im==0));
    }

    /**
      * computes the complex inverse
      * @return inverse comp
      * @throws UNINVERTABLE exception
      */
    inline comp inv(void) const
    {
        _c_type_ t=norm();
        if (t==0) throw UNINVERTABLE;
        return conj().mult(1/norm());
    }

    //divide
    inline comp div(comp const& op) const
    {
        return mult(op.inv());
    }

    inline comp meb_trans(const comp& a , const comp& b , const comp& c , const comp& d) const
    {
        comp res=this->mult(a).add(b);
        res = res.div(this->mult(c).add(d));
        return res;
    }

    //square
    inline comp sqr_c(void) const
    {
        return this->mult(*this);
    }

    //power
    inline comp pow(_c_type_ pow) const
    {
        return comp(std::pow(this->modul() , pow) , this->phi()*pow , NULL);
    }

    //natural logarithm
    inline comp ln(void) const
    {
        if (this->eqauls(0)) throw ZERO_LN_ARG;
        return comp(log(this->modul())/log( M_E ) , this->phi());
    }

    //exp
    inline comp exp(void) const
    {
        return comp( std::exp(re) , im  , NULL);
    }

    //print
    void print(void);

    //error message
    static char* err_msg(int i)
    {
        if (i==UNINVERTABLE) return "Uninvertible matrix";
        else return "No Errors";
    }

    //distance in R_2 metrics of two points
    static _c_type_ dist(const comp& op1, const comp& op2)
    {
        return (op1.add(op2.mult(-1))).modul();
    }
};

#endif // COMP_H
