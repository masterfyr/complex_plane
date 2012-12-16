#include <stdio.h>
#include <assert.h>

#include "comp_set.h"
#include "comp.h"
#include "impl_console.h"


#include <stdio.h>
#include <iostream>

using namespace std;

#include <ctime>
long time_test(void (&f)(void),long rounds)
{
    long t=clock();
    for (int i=0;i<rounds;i++)
    {
        f();
    }
    t=clock()-t;
    return t;
}

void test_comp()
{
    assert(true);
    comp a={1,12};
    comp b={1,-12};
    assert(_c_mult(a,b).re==_c_norm(a));
    a=_c_get_s(0,1);
    b=_c_get_s(0,-1);
    _c_inv(a,a);
    assert(_c_eqauls(a,b));
 //   assert(_c_equals(a);
    assert((b.re==0)&&(b.im==-1));
 //   a.set(0,1);
 //   assert(_c_phi(a)==M_PI/2);
    _c_mult(a,a);
 //   assert(_c_phi(a)==M_PI);
    try{
    for (int j=0;j<10;j++)
    for (int i=0;i<10;i++)
        _c_meb_trans(_c_get_r(1),_c_get_r(2),_c_get_r(1),_c_get_r(1),a,a);
    }
    catch (_c_exception error)
    {
        std::cout<<"ERROR "<<error<<" : ";
        std::cout<<_c_err_msg(error)<<"\n";
    }
}

void test_comp_set()
{
    comp z={1,1};
    comp_set x;
    for (int i=0;i<5;i++)
    {
        x.add_to_set(z);
        z=_c_mult(z,z);
    }
    x.print();

    x=x.meb_trans(comp_r(0), comp_r(1), comp_r(1), comp_r(0));

    z=comp_s(0,1);
    comp_set x1;
    x1.add_to_set(z);

    for (int i=0;i<5;i++)
    {
        x1=x1.sqrt_full();
        x1=x1-comp_r(1);
    }

    x.print();

    x1.print();
    cout<<x1.size();
}
