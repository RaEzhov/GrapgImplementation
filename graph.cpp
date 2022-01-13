#include "graph.h"

void graph::new_vertex() {
    auto new_vertex = new vertex_of_graph;
    vertices_map[new_vertex->id()] = new_vertex;
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
            vertices_map[new_vertex->id()] = new_vertex;
        } else {
            exit(-1); // One or more vertices are not exist
        }
    }
}

std::ostream& operator<< (std::ostream &out, const graph &this_graph) {
    std::string str;
    str.reserve(this_graph.size()*20);
    for (const auto i: this_graph.vertices_map) {
        str += "Vertex: " + std::to_string(i.first) + "\nEdges: ";
        for (auto j: i.second->edges) {
            str += std::to_string(j->id()) + " ";
        }
        str += "\n";
    }
    out << str;
    return out;
}

void graph::check_vertices(std::unordered_map<int, vertex_of_graph*>::iterator first, std::unordered_map<int, vertex_of_graph*>::iterator second) {
    if(first == second){
        exit(-1); // first == second
    }
    if (first == vertices_map.end() or second == vertices_map.end()){
        exit(-1); // first vertex or second vertex is not exists
    }
}


void graph::new_edge(size_t first, size_t second) {
    std::pair<std::unordered_map<int, vertex_of_graph*>::iterator , std::unordered_map<int, vertex_of_graph*>::iterator> iterators;
    iterators.first = vertices_map.find(first);
    iterators.second = vertices_map.find(second);
    check_vertices(iterators.first, iterators.second);
    for (auto i: iterators.first->second->edges){
        if (second == i->id()){
            exit(-1); // edge already exists
        }
    }
    iterators.first->second->edges.push_back(iterators.second->second);
    iterators.second->second->edges.push_back(iterators.first->second);
}

size_t graph::size() const {
    return vertices_map.size();
}

void graph::delete_vertex(size_t id) {
    if (vertices_map.find(id) == vertices_map.end()){
        exit(-1); // there is no such vertex in the graph
    }
    for (auto edge:vertices_map[id]->edges){
        edge->edges.remove(vertices_map[id]);
    }
    delete vertices_map[id];
    vertices_map.erase(id);
}

void graph::delete_edge(size_t first, size_t second) {
    std::pair<std::unordered_map<int, vertex_of_graph*>::iterator , std::unordered_map<int, vertex_of_graph*>::iterator> iterators;
    iterators.first = vertices_map.find(first);
    iterators.second = vertices_map.find(second);
    check_vertices(iterators.first, iterators.second);
    iterators.first->second->edges.remove(iterators.second->second);
    iterators.second->second->edges.remove(iterators.first->second);
}

vertex_of_graph &graph::operator[](size_t id) {
    auto iter = vertices_map.find(id);
    if (iter == vertices_map.end()){
        exit(-1); // No this key in map
    }
    return *vertices_map[id];
}
