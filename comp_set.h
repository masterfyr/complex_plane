#ifndef COMP_SET_H
#define COMP_SET_H

#include <vector>

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

        //function of: is there an element in the set or not?
        //return the position of the element or -1 if there is no such element
        int get_pos(const comp& val) const
        {
            for (unsigned int i=0;i<set.size();i++)
            {
                if (_c_eqauls(set.at(i),val)) return i;
            }
            return -1;
        }

        //add the element in the end
        void add_to_set(comp const& val)
        {
            set.push_back(val);
        }

        //make the mebius transformation
        comp_set meb_trans(const comp& a , const comp& b , const comp& c , const comp& d) const
        {
            vector<comp> s = this->get_set();
            comp_set res;
            int err; //error code
            for (unsigned int i=0;i<this->get_set().size();i++)
            {
                if ((err=_c_meb_trans(a,b,c,d,s.at(i),s.at(i)))!=NO_EXCEPTION) throw err;
                res.add_to_set(s.at(i));
            }
            return res;
        }

        //the size of the set
        unsigned int size(void) const
        {
            return set.size();
        }

        //the union of sets
        comp_set cup(const comp_set& op) const
        {
            comp_set res(op);
            for (unsigned int i=0;i<set.size();i++)
            {
                int j=op.get_pos(set.at(i));
                if (j==-1) res.add_to_set(set.at(i));
            }
            return res;
        }

        //multiplication by a value
        comp_set operator*(const comp& val) const
        {
            comp_set res;
            for (unsigned int i=0;i<set.size();i++)
            {
                res.add_to_set(_c_mult(set.at(i),val));
            }
            return res;
        }

        //power of the set
        comp_set operator^(_c_type op) const
        {
            comp_set res;
            for (unsigned int i=0;i<set.size();i++)
            {
                res.add_to_set(_c_pow(set.at(i),op));
            }
            return res;
        }

        //add a constant (translation by a constant)
        comp_set operator+(const comp& op) const
        {
            comp_set res;
            for (unsigned int i=0;i<set.size();i++)
            {
                res.add_to_set(_c_add(set.at(i),op));
            }
            return res;
        }

        //add a -constant (translation by a -constant)
        comp_set operator-(const comp& op) const
        {
            comp_set res;
            for (unsigned int i=0;i<set.size();i++)
            {
                res.add_to_set(_c_add(set.at(i),_c_mult(op,comp_r(-1))));
            }
            return res;
        }


        //square root of the set
        //the union of dirrect root and - if it
        comp_set sqrt_full() const
        {
            comp_set res(*this^(0.5));
            comp t={-1,0};
            res=res.cup(res*t);
            return res;
        }

        void print(void);
};

#endif // COMP_SET_H
