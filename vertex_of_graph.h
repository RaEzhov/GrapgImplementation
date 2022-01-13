#ifndef VERTEX_OF_GRAPH_H
#define VERTEX_OF_GRAPH_H

#include <unordered_map>
#include <string>
#include <list>

class vertex_of_graph {
public:
    std::list<vertex_of_graph *> edges;

    size_t id() const;

    int& operator[](const std::string &key);

    vertex_of_graph();

    ~vertex_of_graph();

private:
    size_t identifier;
    std::unordered_map<std::string, int> vertex_map;
    static size_t amount_of_vertices;
};


#endif//VERTEX_OF_GRAPH_H