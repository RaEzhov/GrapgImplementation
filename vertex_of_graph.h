#ifndef VERTEX_OF_GRAPH_H
#define VERTEX_OF_GRAPH_H

#include <unordered_map>
#include <string>
#include <list>

enum vertex_color{WHITE, GRAY, BLACK};

class vertex_of_graph {
public:
    vertex_color color;

    std::list<vertex_of_graph *> edges;

    size_t id() const;

    bool key_exists(const std::string& key) const;

    int& operator[](const std::string &key);

    const int& operator[](const std::string &key) const;

    vertex_of_graph();

    ~vertex_of_graph();

private:
    size_t identifier;
    std::unordered_map<std::string, int> vertex_map;
    static size_t amount_of_vertices;
};


#endif//VERTEX_OF_GRAPH_H