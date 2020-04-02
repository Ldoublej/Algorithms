//
// Created by ldoublej on 2020/4/1.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;



//common function
void print_vector(const vector<int> & v)
{
    ostream_iterator<int> out(cout," ");
    copy(v.cbegin(),v.cend(),out);
}
void exchange(int lsh, int rsh, vector<int> & v)
{
    int temp = v.at(lsh);
    v.at(lsh) = v.at(rsh);
    v.at(rsh) = temp;
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
                exchange(min,j,v);
        }
    }
}

void insertion(vector<int> & v)
{
    for(int i = 1;i < v.size();++i)
    {
        int current = v.at(i);
        int j = i - 1;
        for(;j >= 0;--j)
        {
            if(current < v.at(j))
                v.at(j+1) = v.at(j);
            else
                break;
        }
        v.at(j+1) = current;
    }
}

void shell(vector<int> & v)
{
    int n = v.size();
    int h = 1;

    while(h < n/3) h = 3*h + 1;
    cout << h << endl;

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

#endif //SORTING_SORTING_H
