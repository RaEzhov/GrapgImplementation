#include "vertex_of_graph.h"
vertex_of_graph::vertex_of_graph(){
    id = amount_of_vertices;
    amount_of_vertices++;
}
vertex_of_graph::~vertex_of_graph() {
    amount_of_vertices--;
}
int vertex_of_graph::operator[](std::string &str) {
    return vertex_map[str];
}

size_t vertex_of_graph::amount_of_vertices = 0;