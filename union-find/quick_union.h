//
// Created by ldoublej on 2020/3/29.
//

#ifndef UNION_FIND_QUICK_UNION_H
#define UNION_FIND_QUICK_UNION_H

template <int N>
class QuickUnion
{
private:
    int _id[N];
    int _count = N;
public:
    QuickUnion():_id({})
    {
        for(int i = 0;i < N;++i)
        {
            _id[i] = i;
        }
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

        _id[q] = rsh;
        --_count;
    }

    int count()
    {
        return _count;
    }
};

#endif //UNION_FIND_QUICK_UNION_H
