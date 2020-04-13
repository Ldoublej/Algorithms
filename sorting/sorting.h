//
// Created by ldoublej on 2020/4/1.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

typedef vector<int>::iterator pos;

//common function
void print_vector(const vector<int> & v)
{
    ostream_iterator<int> out(cout," ");
    copy(v.cbegin(),v.cend(),out);
    cout << endl;
}
void exchange(vector<int> & v,int lsh, int rsh)
{
    int temp = v.at(lsh);
    v.at(lsh) = v.at(rsh);
    v.at(rsh) = temp;
}
void exchange(pos lsh,pos rsh)
{
    pos::value_type temp = *lsh;
    *lsh = *rsh;
    *rsh = temp;
}
bool is_sorted(const vector<int> & v)
{
    for(int i = 1;i < v.size();++i)
    {
        if(v.at(i-1) > v.at(i))
            return false;
    }
    return true;
}




void selection(vector<int> & v)
{
    for(int i = 0;i < v.size();++i)
    {
        int min = i;
        for(int j = i + 1;j < v.size();++j)
        {
            if(v.at(j) < v.at(min))
                exchange(v,min,j);
        }
    }
}
//iterator edition
void selection(vector<int> & v,pos lo,pos hi)
{
    while(lo <= hi)
    {
        for(pos i = lo + 1;i <=hi;++i)
        {
            if(*i < *lo)
                exchange(i,lo);
        }
        lo++;
    }
}

void insertion(vector<int> & v)
{
    for(int i = 1;i < v.size();++i)
    {
        int current = v.at(i);
        int j = i - 1;
        for(;j >= 0&&current < v.at(j);--j)
        {
            v.at(j+1) = v.at(j);
        }
        v.at(j+1) = current;
    }
}
//iterator edition
void insertion(vector<int> & v,pos lo,pos hi)
{
    for(pos i = lo + 1;i <= hi;++i)
    {
        int current = *i;
        pos j = i -1;
        for(;j >= lo && *j > current;--j)
        {
            *(j+1) = *j;
        }
        *(j+1) = current;
    }
}
//iterator edition
void shell(vector<int> & v,pos lo,pos hi)
{
    int n = hi - lo;
    int h = 1;

    while(h < n/3) h = 3*h + 1;

    while(h >= 1)
    {
        for(pos i = lo;i <= hi;++i)
        {
            int current = *i;
            pos j = i -h;
            for(;j >= lo && current < *j;j -= h)
            {
                *(j+h) = *j;
            }
            *(j+h) = current;
        }
        h /= 3;
    }
}

void shell(vector<int> & v)
{
    int n = v.size();
    int h = 1;

    while(h < n/3) h = 3*h + 1;

    while(h >= 1)
    {
        for(int i = h;i < v.size();++i)
        {
            int key = v.at(i);
            int j = i - h;
            for(;j >= 0;j -=h)
            {
                if(v.at(j) > key)
                    v.at(j+h) = v.at(j);
                else
                    break;
            }
            v.at(j+h) = key;
        }
        h /= 3;
    }
}


void merge_vector(vector<int> & v,pos b,pos m,pos e)
{
    if(e == v.end())
        e = v.end() - 1;
    vector<int> v_copy(b,e+1);

    int mid = m - b;
    int delta = b - v.begin();

    int lsh = 0;
    int rsh = mid + 1;

    for(int i = 0;i < v_copy.size();++i)
    {
        if(lsh > mid)
            v.at(delta + i) = v_copy.at(rsh++);
        else if(rsh >= v_copy.size())
            v.at(delta + i) = v_copy.at(lsh++);
        else if(v_copy.at(lsh) < v_copy.at(rsh))
            v.at(delta + i) = v_copy.at(lsh++);
        else
            v.at(delta + i) = v_copy.at(rsh++);
    }
}
void merge(vector<int> & v,pos b,pos e)
{
    if(e == v.end())
        e -= 1;
    if(e - b == 0)
        return;
    pos m = b + (e - b) / 2;
    merge(v,b,m);
    merge(v,m+1,e);
    merge_vector(v,b,m,e);
}

void quick_3way(vector<int> & v,pos lo,pos hi)
{
    if(lo >= hi) return;
    int key = *lo;
    pos lt = lo;
    pos gt = hi;
    pos i = lt + 1;

    while(i <= gt)
    {
        int i_value = *i;
        if(i_value < key) exchange(lt++,i++);
        else if(i_value > key) exchange(gt--,i);
        else ++i;
    }

    quick_3way(v,lo,lt-1);
    quick_3way(v,gt+1,hi);
}
pos partition(vector<int> & v,pos lo,pos hi)
{
    int key = *lo;
    pos i = lo;
    pos j = hi + 1;


    while(true)
    {
        while(*(++i) < key) if(i > hi) break;
        while(*(--j) > key);
        if(i >= j) break;
        exchange(i,j);
    }
    exchange(lo,j);
    return j;
}


void quick(vector<int> & v,pos lo,pos hi)
{
    if(lo >= hi)
        return;
    pos j = partition(v,lo,hi);

    quick(v,lo,j-1);
    quick(v,j+1,hi);
}


void sink(vector<int> & v,int k,int n)
{
    while(2*k <= n)
    {
        int j = 2*k;
        if(j < n && v.at(j-1) < v.at(j)) ++j;
        if(v.at(k-1) > v.at(j-1)) break;
        exchange(v,k-1,j-1);
        k = j;
    }
}
void heap(vector<int> & v)
{
    int n = v.size();
    for(int i = n/2;i >= 1;--i)
    {
        sink(v,i,n);
    }
    while(n > 1)
    {
        exchange(v,0,--n);
        sink(v,1,n);
    }

}
#endif //SORTING_SORTING_H
