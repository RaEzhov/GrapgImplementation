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
            exit(-1);
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