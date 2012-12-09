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
        comp_set()
        {
            set=vector<comp>(0);
        }

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
        void add(comp const& val)
        {
            set.push_back(val);
        }

        //make the mebius transformation
        comp_set meb_trans(const comp& a , const comp& b , const comp& c , const comp& d) const
        {
            vector<comp> s = this->get_set();
            comp_set res;
            for (int i=0;i<this->get_set().size();i++)
            {
                res.add(s.at(i).meb_trans(a,b,c,d));
            }
            return res;
        }

        void print(void);
};

#endif // COMP_SET_H
