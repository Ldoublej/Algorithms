//
// Created by ldoublej on 2020/5/8.
//

#ifndef GRAPH_CC_H
#define GRAPH_CC_H

#include "undirected_graph.h"

class CC
{
public:
    explicit CC(Graph & g): udg(g)
    {
        int sz = g.vertex_count();
        marked = new bool[sz];
        id = new int[sz];

        for(int i = 0;i < sz;++i)
        {
            if(!marked[i])
            {
                counter++;
                dfs(i);
            }
        }

    }
    bool is_connected(int v,int w)
    {
        return id[v] == id[w];
    }
private:
    bool * marked;
    int * id;
    int counter = 0;
    Graph & udg;

    void dfs(int s)
    {
        marked[s] = true;
        id[s] = counter;
        for(auto i : udg.adj(s))
        {
            if(!marked[i])
            {
                dfs(i);
            }
        }
    }
};

#endif //GRAPH_CC_H
