#include "vertex_of_graph.h"
vertex_of_graph::vertex_of_graph(){
    identifier = amount_of_vertices;
    amount_of_vertices++;
}
vertex_of_graph::~vertex_of_graph() {
    amount_of_vertices--;
}
size_t vertex_of_graph::id() const {
    return identifier;
}

int vertex_of_graph::operator[](std::string &str) {
    return vertex_map[str];
}

size_t vertex_of_graph::amount_of_vertices = 0;