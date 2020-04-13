//
// Created by ldoublej on 2020/4/10.
//

#ifndef PRIORITY_QUEUE_MAXPQ_H
#define PRIORITY_QUEUE_MAXPQ_H

#include <memory>
#include <iostream>


template <typename T,typename _Alloc = std::allocator<T>>
class MaxPQ
{
public:
    explicit MaxPQ(int n);
    void insert(const T & i);
    T del_max();
    bool is_empty();
    size_t size();

    void debug()
    {
        for(int i = 1;i < _sz+1;++i)
        {
            std::cout << *(_data+i) << std::endl;
        }
    }
private:
    int _sz = 0;
    int _construct_next_time = 1;
    int _capacity;
    _Alloc _allocator;
    typename _Alloc::pointer _data;

    void sink(int k);
    void swim(int k);

    bool less_value(int lsh,int rsh)
    {
        return *(_data+lsh) < *(_data+rsh);
    }
    void exchange(int lsh,int rsh)
    {
        T temp{};
        temp = *(_data+lsh);
        *(_data+lsh) = *(_data+rsh);
        *(_data+rsh) = temp;
    }
};



template <typename T,typename _Alloc>
bool MaxPQ<T,_Alloc>::is_empty()
{
    return _sz <= 0;
}

template <typename T,typename _Alloc>
size_t MaxPQ<T,_Alloc>::size()
{
    return _sz;
}

template <typename T,typename _Alloc>
MaxPQ<T,_Alloc>::MaxPQ(int n):_capacity(n <= 0 ? 1:n+1)
{
    _data =  _allocator.allocate(_capacity);
}

template <typename T,typename _Alloc>
void MaxPQ<T,_Alloc>::sink(int k)
{
    while(2*k <= _sz)
    {
        int j = 2*k;
        if(j < _sz && less_value(j,j+1)) ++j;
        if(!less_value(k,j))
            break;
        exchange(k,j);
        k = j;
    }
}
template <typename T,typename _Alloc>
void MaxPQ<T,_Alloc>::swim(int k)
{
    while(k/2 >= 1 && less_value(k/2,k))
    {
        exchange(k/2,k);
        k = k / 2;
    }
}
template <typename T,typename _Alloc>
void MaxPQ<T,_Alloc>::insert(const T& i)
{
    _allocator.construct(_data+_construct_next_time,i);
    swim(_construct_next_time);
    ++_sz;
    ++_construct_next_time;
}

template <typename T,typename _Alloc>
T MaxPQ<T,_Alloc>::del_max()
{
    if(_sz <= 0)
        return T{};

    T ret = *(_data+1);
    exchange(1,_sz);
    _allocator.destroy(_data+_sz);
    --_sz;
    --_construct_next_time;
    if(_sz > 1)
        sink(1);

    return ret;
}
#endif //PRIORITY_QUEUE_MAXPQ_H
