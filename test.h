#include <stdio.h>
#include <assert.h>

#include "comp_set.h"
#include "comp.h"
#include "console_impl.h"


#include <stdio.h>
#include <iostream>

using namespace std;

void test_comp()
{
    assert(true);
    comp a(1,12);
    comp b(1,-12);
    assert(a.mult(b).re==a.norm());
    a.set(0,1);
    b.set(0,-1);
    assert(a.inv().eqauls(b));
    assert(a.div(b).eqauls(-1));
    assert((b.re==0)&&(b.im==-1));
    a.set(0,1);
    assert(a.phi()==M_PI/2);
    a=a.mult(a);
    assert(a.phi()==M_PI);
    try{
    for (int j=0;j<10;j++)
    for (int i=0;i<10;i++)
        a=a.meb_trans((comp) 1,(comp) 2,(comp) 1,(comp) 1);
    }
    catch (int error)
    {
        std::cout<<"ERROR "<<error<<" : ";
        std::cout<<comp::err_msg(error)<<"\n";
    }

    a=COMP_I;
    a=comp(1,1);
    //a=comp(0,0);
    //a=a.pow(-1);
    a=a.ln();
    a=a.exp();
    a.print();
    printf("Hello\n");
}

void test_comp_set()
{
    comp z(1,1);
    comp_set x;
    for (int i=0;i<5;i++)
    {
        x.add_to_set(z);
        z=z.mult(z);
    }
    x.print();

    x=x.meb_trans(0, 1, 1, 0);

    z=comp(1,0);
    comp_set x1;
    x1.add_to_set(z);

    for (int i=0;i<5;i++)
    {
        x1=x1.sqrt_full();
        x1=x1-1;
    }

    x.print();

    x1.print();
    cout<<x1.size();
}
