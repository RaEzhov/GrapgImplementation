#include "vertex_of_graph.h"
vertex_of_graph::vertex_of_graph(){
    identifier = amount_of_vertices;
    amount_of_vertices++;
    color = WHITE;
}
vertex_of_graph::~vertex_of_graph() {
    amount_of_vertices--;
}
size_t vertex_of_graph::id() const {
    return identifier;
}

size_t vertex_of_graph::amount_of_vertices = 0;

int &vertex_of_graph::operator[](const std::string &key) {
    return vertex_map[key];
}
