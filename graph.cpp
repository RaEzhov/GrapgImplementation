#include "graph.h"

void graph::new_vertex() {
    auto new_vertex = new vertex_of_graph;
    vertices_map[new_vertex->id] = new_vertex;
}
graph::~graph() {
    for (auto i:vertices_map) {
        delete i.second;
    }
}
void graph::new_vertex(std::initializer_list<int> edges_list) {
    auto new_vertex = new vertex_of_graph;
    for (auto edge: edges_list) {
        auto vIter = vertices_map.find(edge);
        if (vIter != vertices_map.end()) {
            new_vertex->edges.push_back(vIter->second);
            vIter->second->edges.push_back(new_vertex);
            vertices_map[new_vertex->id] = new_vertex;
        } else {
            exit(-1); // One or more vertices are not exist
        }
    }
}

std::ostream& operator<< (std::ostream &out, const graph &this_graph) {
    std::string str;
    for (auto i: this_graph.vertices_map) {
        str += "Vertex: " + std::to_string(i.first) + "\nEdges: ";
        for (auto j: i.second->edges) {
            str += std::to_string(j->id) + " ";
        }
        str += "\n";
    }
    out << str;
    return out;
}

void graph::new_edge(int first, int second) {
    if(first == second){
        exit(-1); // first == second
    }
    auto first_iter = vertices_map.find(first);
    auto second_iter = vertices_map.find(second);
    if (first_iter == vertices_map.end() or second_iter == vertices_map.end()){
        exit(-1); // first vertex or second vertex is not exists
    }
    for (auto i: first_iter->second->edges){
        if (second == i->id){
            exit(-1); // edge already exists
        }
    }
    first_iter->second->edges.push_back(second_iter->second);
    second_iter->second->edges.push_back(first_iter->second);
}
