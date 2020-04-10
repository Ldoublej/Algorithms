#include <iostream>

#include "sorting.h"



int main()
{
    vector<int> v = {3,1,2,10,4,1,100,32,40,102,89,23,54,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4};

    quick_3way(v,v.begin(),v.end()-1);
    if(is_sorted(v))
        print_vector(v);
    return 0;
}
