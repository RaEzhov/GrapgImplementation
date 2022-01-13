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

const int& vertex_of_graph::operator[](const std::string &key) const{
    auto res = vertex_map.find(key);
    if (res == vertex_map.end()){
        exit(-1); // No this key
    }
    return res->second;
}

bool vertex_of_graph::key_exists(const std::string& key) const{
    auto it = vertex_map.find(key);
    return it != vertex_map.end();
}

int &vertex_of_graph::operator[](const std::string &key) {
    return vertex_map[key];
}
