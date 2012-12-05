#ifndef COMP_H
#define COMP_H

#include "math.h"

#ifndef type
#define type double
#endif

#define sqr(x) ((x)*(x))


class comp
{
public:

    //real part of the complex number
    double re;

    //imaginary part of the real number
    double im;

    //default constructor
    comp():re(0),im(0){}

    //nondefault constructor
    comp(type _re, type _im): re(_re),im(_im){}

    //set
    void set(type _re, type _im)
    {
        re=_re;
        im=_im;
    }

    //the norm of the number
    type norm(void)
    {
        return sqr(re)+sqr(im);
    }

    //distanse to the zero
    type modul(void)
    {
        return sqrt(norm());
    }

    //addition of two complex numbers
    comp add(const comp& op)
    {
        comp res(re + op.re, im + op.im);
        return res;
    }

    //multiplication of two complex numbers
    comp mult(const comp& op)
    {
        comp res(re*op.re - im*op.im, im*op.re + op.im*re);
        return res;
    }

    comp mult(type op_re)
    {
        comp res(re*op_re, im*op_re);
        return res;
    }

    //conjugation
    comp conj(void)
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
    inline int eqauls(type op_re)
    {
        return ((re==op_re)&&(im==0));
    }


    inline

    //inverse
    comp inv(void)
    {
        return conj().mult(1/norm());
    }

    //divide
    comp div(comp& op)
    {
        return mult(op.inv());
    }

    comp meb_trans(comp z, type a, type b, type c, type d)
    {
 //1       comp den=z.mult(a).add()
    }

};

#endif // COMP_H
