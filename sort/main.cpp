#include <iostream>
#include <functional>
#include <chrono>
#include <numeric>

#include "sort.h"


template <typename SORT,typename... Args>
void evaluate_time(SORT && sort_fun,Args&& ... args)
{
    auto beginTime = std::chrono::high_resolution_clock::now();
    std::invoke(std::forward<SORT>(sort_fun),std::forward<Args>(args)...);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime= std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime);
    std::cout << " compute time is " << elapsedTime.count() << " milliseconds" << std::endl;
}


int main()
{
    vector<int> v;
    v.reserve(1000000);
    for(int i =  1000000;i >= 0;i--)
    {
        v.push_back(i);
    }

    //evaluate_time<void(vector<int>&)>(insertion,v);
    evaluate_time(heap,v);
    //evaluate_time<void(vector<int>&,pos,pos)>(selection,v,v.begin(),v.end()-1);
    //evaluate_time<void(vector<int>&,pos,pos)>(merge,v,v.begin(),v.end()-1);
    //evaluate_time<void(vector<int>&,pos,pos)>(quick,v,v.begin(),v.end()-1);
    //evaluate_time<void(vector<int>&,pos,pos)>(shell,v,v.begin(),v.end()-1);

    return 0;
}
