#include <iostream>
#include "MaxPQ.h"
#include <vector>

using namespace std;






int main()
{

    MaxPQ<int> d(100);
    for(int i = 0;i < 100;++i)
    {
        d.insert(i);
    }
    for(int i = 0;i < 100;++i)
    {
        cout << d.del_max() << endl;
    }

    return 0;
}
