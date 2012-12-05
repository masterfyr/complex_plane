#include <stdio.h>
#include <assert.h>
#include "comp.h"

void test()
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
}
