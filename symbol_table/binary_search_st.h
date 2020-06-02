//
// Created by ldoublej on 2020/4/14.
//

#ifndef SYMBOL_TABLE_BINARY_SEARCH_ST_H
#define SYMBOL_TABLE_BINARY_SEARCH_ST_H

#include <iostream>

template <typename K,typename V,unsigned int N = 100>
class BinarySearchST
{
public:
    BinarySearchST() = default;
    void put(const K & k,const V & v);
    V* get(const K & k);
    void del(const K & k);
    bool is_contain(const K & k);
    int size();
    bool is_empty();
private:
    K _keys[N];
    V _vals[N];
    int _sz = 0;

    int rank(const K & k);
};

template<typename K, typename V, unsigned int N>
int BinarySearchST<K, V, N>::rank(const K &k)
{
    int lo = 0;
    int hi = _sz - 1;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(_keys[mid] > k)
            hi = mid - 1;
        else if(_keys[mid] < k)
            lo = mid + 1;
        else
            return mid;
    }

    return lo;
}

template<typename K, typename V, unsigned int N>
void BinarySearchST<K, V, N>::put(const K &k, const V &v)
{
    int i = rank(k);
    if(i < _sz && _keys[i] == k) {
        _vals[i] = v;
        return;
    }
    if(_sz + 1 > N)
    {
        std::cout << "fail to add element!" << std::endl;
        return;
    }
    for(int j = _sz;j > i;--j)
    {
        _keys[j] = _keys[j-1];
        _vals[j] = _vals[j-1];
    }
    _keys[i] = k;
    _vals[i] = v;
    ++_sz;
}

template<typename K, typename V, unsigned int N>
V* BinarySearchST<K, V, N>::get(const K &k)
{
    int lo = 0;
    int hi = _sz-1;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(_keys[mid] > k)
            hi = mid - 1;
        else if(_keys[mid] < k)
            lo = mid + 1;
        else
            return &_vals[mid];
    }
    return nullptr;
}

template<typename K, typename V, unsigned int N>
bool BinarySearchST<K, V, N>::is_contain(const K &k)
{
    int i = rank(k);
    return _keys[i] == k;
}

template<typename K, typename V, unsigned int N>
bool BinarySearchST<K, V, N>::is_empty()
{
    return _sz == 0;
}

template<typename K, typename V, unsigned int N>
int BinarySearchST<K, V, N>::size()
{
    return _sz;
}

template<typename K, typename V, unsigned int N>
void BinarySearchST<K, V, N>::del(const K &k)
{
    int i = rank(k);
    if(i < _sz && _keys[i] == k)
    {
        for(int j = i;j < _sz;++j)
        {
            _keys[j] = _keys[j+1];
            _vals[j] = _vals[j+1];
        }
        --_sz;
    }
}

#endif //SYMBOL_TABLE_BINARY_SEARCH_ST_H
