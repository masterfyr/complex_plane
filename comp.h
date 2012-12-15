#ifndef COMP_H
#define COMP_H

//define basic math constants
#define _USE_MATH_DEFINES
#undef _MATH_DEFINES_DEFINED

//include math arithmetics

#include "math.h"

//define the specific type of real part of
//the complex numbers
#define _c_type_ double

//define the square function
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
    comp();

    //nondefault constructor
    comp(_c_type_ _re, _c_type_ _im);

    //constructor from real value
    comp(_c_type_ _re);

    //constructor from polar coordinates
    comp(_c_type_ rho, _c_type_ phi, int);

    //setter
    inline void set(_c_type_ _re, _c_type_ _im);

    //the norm of the number
    inline _c_type_ norm(void) const;

    //distanse to the zero
    inline _c_type_ modul(void) const;

    //angle
    inline _c_type_ phi(void) const;

    //addition of two complex numbers
    inline comp add(const comp& op) const;

    //multiplication of two complex numbers
    inline comp mult(const comp& op) const;

    //multiplication by a real constant
    inline comp mult(_c_type_ op_re) const;

    //conjugation
    inline comp conj(void) const;

    //equality
    inline int eqauls(const comp& op) const;

    //equality
    inline int eqauls(_c_type_ op_re) const;

    /**
      * computes the complex inverse
      * @return inverse comp
      * @throws UNINVERTABLE exception
      */
    inline comp inv(void) const;
    //divide
    inline comp div(comp const& op) const;

    inline comp meb_trans(const comp& a , const comp& b , const comp& c , const comp& d) const;

    //square
    inline comp sqr_c(void) const;

    //power
    inline comp cpow(_c_type_ arg) const;

    //natural logarithm
    inline comp ln(void) const;

    //exp
    inline comp cexp(void) const;

    //print
    void print(void);

    //error message
    static char* err_msg(int i);

    //distance in R_2 metrics of two points
    static _c_type_ dist(const comp& op1, const comp& op2);

    //operator of equality
    int operator== (const comp& op1) const;

    //operator of the addition
    comp operator+(const comp& op1) const;
    //operator of the multiplication
    comp operator*(const comp& op1) const;

    //operator: power of the num
    comp operator^(_c_type_ op1) const;

    //operator difference
    comp operator-(const comp& op) const;
};

#endif // COMP_H
