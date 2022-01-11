#ifndef GRAPH_H
#define GRAPH_H
#include "vertex_of_graph.h"

class graph {
public:
    void newVertex();

    void newVertex(std::initializer_list<int> edgesList);

    friend std::ostream &operator<<(std::ostream &out, const graph &this_graph);

    ~graph();

private:
    std::unordered_map<int, vertexOfGraph *> vertices_map;
};

#endif//GRAPH_H
