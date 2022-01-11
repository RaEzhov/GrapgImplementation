#ifndef VERTEX_OF_GRAPH_H
#define VERTEX_OF_GRAPH_H

#include <unordered_map>
#include <string>
#include <list>

class vertexOfGraph {
public:
    size_t id;
    std::list<vertexOfGraph *> edges;

    int operator[](std::string &str);

    vertexOfGraph();

    ~vertexOfGraph();

private:
    std::unordered_map<std::string, int> vertexMap;
    static size_t amount_of_vertices;
};


#endif//VERTEX_OF_GRAPH_H
