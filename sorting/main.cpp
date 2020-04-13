#include <iostream>

#include "sorting.h"



int main()
{
    vector<int> v = {3,1,2,10,4,1,100,32,40,102,89,23,54,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4};
    vector<int> v1 = {7,6,5,4,3,2,1,0};

    heap(v);
    if(is_sorted(v))
        print_vector(v);
    return 0;
}
