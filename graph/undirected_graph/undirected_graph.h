//
// Created by ldoublej on 2020/4/23.
//

#ifndef GRAPH_UNDIRECTED_GRAPH_H
#define GRAPH_UNDIRECTED_GRAPH_H

#include <iterator>
#include <vector>
#include <algorithm>

#ifndef DIGRAPH
#define GRAPH_NAME Graph
#else
#define GRAPH_NAME Digraph
#endif

class GRAPH_NAME
{
public:
    explicit Graph(int sz): v_sz(sz)
    {
        node = new std::vector<int>[v_sz];
    }
    Graph(const Graph & g): v_sz(g.vertex_count())
    {
        node = new std::vector<int>[v_sz];
        for(int i = 0;i < v_sz;++i)
        {
            std::vector<int> & out = node[i];
            std::vector<int> & in = g.node[i];
            std::copy(in.begin(),in.end(),std::back_insert_iterator<std::vector<int>>(out));
        }
    }
    Graph(Graph && g) noexcept: node(g.node), v_sz(g.vertex_count())
    {
        g.node = nullptr;
    }
    int vertex_count() const
    {
        return v_sz;
    }
    int edge_count() const
    {
        return e_sz;
    }
    std::vector<int> adj(int v) const
    {
        return (node[v]);
    }
    void add_edge(int v,int w)
    {
        node[v].push_back(w);
#ifndef DIGRAPH
        node[w].push_back(v);
#endif
        ++e_sz;
    }


    Graph & operator=(const Graph & g)
    {
        if(this == &g)
            return *this;
        this->v_sz = g.v_sz;
        delete [] node;
        node = new std::vector<int>[v_sz];
        for(int i = 0;i < v_sz;++i)
        {
            std::vector<int> & out = node[i];
            std::vector<int> & in = g.node[i];
            std::copy(in.begin(),in.end(),std::back_insert_iterator<std::vector<int>>(out));
        }
        return *this;
    }
    Graph & operator=(Graph && g) noexcept
    {
        this->v_sz = g.v_sz;
        this->node = g.node;
        g.node = nullptr;
        g.v_sz = 0;
        return *this;
    }

    ~Graph()
    {
        delete[] node;
    }

private:
    int v_sz;
    int e_sz = 0;
    std::vector<int> * node;
};

#endif //GRAPH_UNDIRECTED_GRAPH_H
