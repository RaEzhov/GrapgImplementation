#ifndef GRAPH_H
#define GRAPH_H
#include "vertex_of_graph.h"

class graph {
public:
    void new_vertex();

    void new_vertex(std::initializer_list<int> edges_list);

    void new_edge(int first, int second);

    friend std::ostream &operator<<(std::ostream &out, const graph &this_graph);

    ~graph();

private:
    std::unordered_map<int, vertex_of_graph *> vertices_map;
};

#endif//GRAPH_H
