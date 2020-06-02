//
// Created by ldoublej on 2020/5/9.
//

#ifndef GRAPH_CYCLE_H
#define GRAPH_CYCLE_H

#include "undirected_graph.h"

class Cycle
{
public:
    explicit Cycle(Graph & udg): g(udg)
    {
        int sz = udg.vertex_count();
        marked = new bool[sz];
        for(int i =0;i < sz;++i)
        {
            if(!marked[i])
                dfs(i,i);
        }
    }
    bool has_cycle() const
    {
        return cycle;
    }
private:
    bool cycle = false;
    bool * marked;
    Graph & g;

    void dfs(int s1,int s2)
    {
        marked[s1] = true;
        for(auto i:g.adj(s1))
        {
            if(!marked[i])
            {
                dfs(i,s1);
            }
            else if(i != s2)
            {
                cycle = true;
            }
        }
    }
};

#endif //GRAPH_CYCLE_H
