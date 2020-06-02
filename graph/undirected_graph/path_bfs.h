//
// Created by ldoublej on 2020/5/8.
//

#ifndef GRAPH_PATH_BFS_H
#define GRAPH_PATH_BFS_H
#include "undirected_graph.h"
#include <queue>

class Path_bfs
{
public:
    Path_bfs(Graph & udg, int s): g(udg), start(s)
    {
        int sz = udg.vertex_count();
        marked = new bool[sz];
        edgeto = new int[sz];
        bfs(start);
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
    void bfs(int s)
    {
        marked[s] = true;
        std::queue<int> queue;
        queue.push(s);

        while(!queue.empty())
        {
            int current = queue.front();
            queue.pop();
            marked[current] = true;
            for(auto i: g.adj(current))
            {
                if(!marked[i])
                {
                    edgeto[i] = current;
                    queue.push(i);
                }
            }
        }

    }
    bool * marked;
    int * edgeto;
    int start;
    Graph & g;
};
#endif //GRAPH_PATH_BFS_H
