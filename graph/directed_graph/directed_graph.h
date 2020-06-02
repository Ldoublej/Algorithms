//
// Created by ldoublej on 2020/5/8.
//

#ifndef GRAPH_DIRECTED_GRAPH_H
#define GRAPH_DIRECTED_GRAPH_H

#include <vector>

class Digraph
{
public:
    explicit Digraph(int sz): v_sz(sz)
    {
        node = new std::vector<int>[v_sz];
    }
    Digraph(const Digraph & g): v_sz(g.vertex_count())
    {
        node = new std::vector<int>[v_sz];
        for(int i = 0;i < v_sz;++i)
        {
            std::vector<int> & out = node[i];
            std::vector<int> & in = g.node[i];
            std::copy(in.begin(),in.end(),std::back_insert_iterator<std::vector<int>>(out));
        }
    }
    Digraph(Digraph && g) noexcept: node(g.node), v_sz(g.vertex_count())
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
        return node[v];
    }
    void add_edge(int v,int w)
    {
        node[v].push_back(w);
        ++e_sz;
    }


    Digraph & operator=(const Digraph & g)
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
    Digraph & operator=(Digraph && g) noexcept
    {
        this->v_sz = g.v_sz;
        this->node = g.node;
        g.node = nullptr;
        g.v_sz = 0;
        return *this;
    }

    ~Digraph()
    {
        delete[] node;
    }

private:
    int v_sz;
    int e_sz = 0;
    std::vector<int> * node;
};

#endif //GRAPH_DIRECTED_GRAPH_H
