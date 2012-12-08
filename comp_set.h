#ifndef COMP_SET_H
#define COMP_SET_H



#include <vector>
//#include <list>

#include "comp.h"

using namespace std;

class comp_set
{
    private:
        vector<comp> set;
    public:
        //default constructor
        comp_set(){}

        //nondefault constructor from array
        comp_set(comp array[], int size)
        {
            set=vector<comp>(size);
            for (int i=0;i<size;i++)
            {
                set.at(i)=array[i];
            }
        }

        //getter
        vector<comp> get_set(void) const
        {
            return set;
        }

        //add the element in the end
        void add(const comp& val)
        {
            set.push_back(val);
        }



        void print(void);
};

#endif // COMP_SET_H
