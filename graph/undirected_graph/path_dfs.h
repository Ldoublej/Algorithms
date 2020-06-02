//
// Created by ldoublej on 2020/5/8.
//

#ifndef GRAPH_PATH_DFS_H
#define GRAPH_PATH_DFS_H
#include "undirected_graph.h"

class Path_dfs
{
public:
    Path_dfs(Graph & udg, int s): g(udg), start(s)
    {
        int sz = udg.vertex_count();
        marked = new bool[sz];
        edgeto = new int[sz];
        dfs(start);
    }
    bool has_path(int e)
    {
        return edgeto[e] != 0;
    }
    std::vector<int> path(int e)
    {
        if(!has_path(e))
            return {};
        std::vector<int> p;
        int ele = e;
        p.push_back(ele);
        while(ele != start)
        {
            ele = edgeto[ele];
            p.push_back(ele);
        }
        return p;
    }
private:
    void dfs(int s)
    {
        marked[s] = true;
        for(auto i : g.adj(s))
        {
            if(!marked[i])
            {
                edgeto[i] = s;
                dfs(i);
            }
        }
    }
    bool * marked;
    int * edgeto;
    int start;
    Graph & g;
};

#endif //GRAPH_PATH_DFS_H
