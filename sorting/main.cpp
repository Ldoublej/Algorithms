#include <iostream>

#include "sorting.h"


int main()
{
    vector<int> v = {10,11,9,12,8,7,6,13,5,5,3,11,1,2,3};
    shell(v);
    if(is_sorted(v))
        print_vector(v);
    return 0;
}
