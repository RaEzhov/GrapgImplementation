#include "vertex_of_graph.h"
vertexOfGraph::vertexOfGraph(){
    id = amount_of_vertices;
    amount_of_vertices++;
}
vertexOfGraph::~vertexOfGraph() {
    amount_of_vertices--;
}
int vertexOfGraph::operator[](std::string &str) {
    return vertexMap[str];
}

size_t vertexOfGraph::amount_of_vertices = 0;