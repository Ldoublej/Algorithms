//
// Created by ldoublej on 2020/3/29.
//

#ifndef UNION_FIND_QUICK_FIND_H
#define UNION_FIND_QUICK_FIND_H


template <int N>
class QuickFind
{
private:
    int _id[N];
    int _count = N;
public:
    QuickFind():_id({0})
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
        return _id[q];
    }

    void connect(int q,int p)
    {
        int lsh = find(q);
        int rsh = find(p);
        if(lsh == rsh)
            return;
        for(int i = 0;i < N;++i)
        {
            if(_id[i] == rsh)
            {
                _id[i] = lsh;
            }
        }
        --_count;
    }

    int count()
    {
        return _count;
    }
};

#endif //UNION_FIND_QUICK_FIND_H
