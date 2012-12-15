#ifndef CONSOLE_IMPL_H
#define CONSOLE_IMPL_H

/*
 * This header file contains the implementation of all the function
 * using the console
 */

#include "comp.h"
#include "comp_set.h"

//print in console the comp variable
void comp::print(void)
{
    printf("Re: %lf, --- Im: %lf\n",re,im);
}

void comp_set::print(void)
{
    for (unsigned int i=0;i<set.size();i++)
    {
        set.at(i).print();
    }
}


#endif // CONSOLE_IMPL_H
