#include "graph.h"

void graph::newVertex() {
    auto newVertex = new vertexOfGraph;
    vertices_map[newVertex->id] = newVertex;
}
graph::~graph() {
    for (auto i:vertices_map) {
        delete i.second;
    }
}
void graph::newVertex(std::initializer_list<int> edgesList) {
    auto newVertex = new vertexOfGraph;
    for (auto edge: edgesList) {
        auto vIter = vertices_map.find(edge);
        if (vIter != vertices_map.end()) {
            newVertex->edges.push_back(vIter->second);
            vIter->second->edges.push_back(newVertex);
            vertices_map[newVertex->id] = newVertex;
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

void graph::newEdge(int first, int second) {
    if(first == second){
        exit(-1); // first == second
    }
    auto firstIter = vertices_map.find(first);
    auto secondIter = vertices_map.find(second);
    if (firstIter == vertices_map.end() or secondIter == vertices_map.end()){
        exit(-1); // first vertex or second vertex is not exists
    }
    for (auto i: firstIter->second->edges){
        if (second == i->id){
            exit(-1); // edge already exists
        }
    }
    firstIter->second->edges.push_back(secondIter->second);
    secondIter->second->edges.push_back(firstIter->second);
}
