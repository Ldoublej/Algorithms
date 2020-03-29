#include <iostream>
#include <iterator>
#include <vector>

#include "quick_find.h"
#include "quick_union.h"
#include "weighted_quick_union.h"

using namespace std;


template <typename T>
int test(const vector<int> & data)
{
    if(data.size() % 2 != 0)
        return -1;

    T uf;

    for(int i = 0;i < data.size();i += 2)
    {
        uf.connect(data.at(i),data.at(i+1));
    }

    return uf.count();
}


int main()
{

    //read q & p
    istream_iterator<int> input_iter(cin);
    istream_iterator<int> eof;
    vector<int> d;
    while(input_iter != eof)
    {
        int q = *input_iter;
        ++input_iter;
        d.push_back(q);
    }

    cout << test<WeightedQuickUnion<10>>(d) << endl;

    return 0;
}
