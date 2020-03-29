//
// Created by ldoublej on 2020/3/30.
//

#ifndef UNION_FIND_WEIGHTED_QUICK_UNION_H
#define UNION_FIND_WEIGHTED_QUICK_UNION_H

#include <algorithm>

template <int N>
class WeightedQuickUnion
{
private:
    int _id[N];
    int _sz[N];
    int _count = N;
public:
    WeightedQuickUnion():_id({}),_sz({})
    {
        for(int i = 0;i < N;++i)
        {
            _id[i] = i;
        }
        std::fill_n(std::begin(_sz),N,1);
    }

    bool connected(int q,int p)
    {
        int lsh = find(q);
        int rsh = find(p);
        return lsh == rsh;
    }

    int find(int q)
    {
        while(q != _id[q])
            q = _id[q];
        return q;
    }

    void connect(int q,int p)
    {
        int lsh = find(q);
        int rsh = find(p);
        if(lsh == rsh)
            return;


        //总是将小树连接到大叔
        if(_sz[lsh] < _sz[rsh])
        {
            _id[lsh] = rsh;
            _sz[rsh] += _sz[lsh];
        }
        else
        {
            _id[rsh] = lsh;
            _sz[lsh] += _sz[rsh];
        }
        --_count;
    }

    int count()
    {
        return _count;
    }
};

#endif //UNION_FIND_WEIGHTED_QUICK_UNION_H
