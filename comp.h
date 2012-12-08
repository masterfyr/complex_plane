#ifndef COMP_H
#define COMP_H

#include "math.h"

#define _c_type_ double

#define sqr(x) ((x)*(x))

#define M_PI       3.14159265358979323846

class comp
{
public:

    static const int UNINVERTABLE= 1;

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
        _c_type_ t=acos(re/norm());
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
    inline int eqauls(const comp& op)
    {
        return ((re==op.re)&&(im==op.im));
    }
    //equality
    inline int eqauls(_c_type_ op_re)
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

    void print(void);

    static char* err_msg(int i)
    {
        if (i==UNINVERTABLE) return "Uninvertible matrix";
        else return "No Errors";
    }

};

#endif // COMP_H
