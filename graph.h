#ifndef GRAPH_H
#define GRAPH_H
#include "vertex_of_graph.h"

class graph {
public:
    void new_vertex();

    void new_vertex(std::initializer_list<int> edges_list);

    void new_edge(size_t first, size_t second);

    void new_edge(std::initializer_list<std::pair<size_t, size_t>> init_list);

    void delete_vertex(size_t id);

    void delete_edge(size_t first, size_t second);

    size_t size() const;

    friend std::ostream &operator<<(std::ostream &out, const graph &this_graph);

    vertex_of_graph& operator[](size_t id);

    void depth_first_search(void (func)(const vertex_of_graph&)) const;

    void breadth_first_search(void (func)(const vertex_of_graph&)) const;

    ~graph();

private:
    std::unordered_map<int, vertex_of_graph *> vertices_map;

    void check_vertices(std::unordered_map<int, vertex_of_graph*>::iterator, std::unordered_map<int, vertex_of_graph*>::iterator) const;

    void dfs_visit(vertex_of_graph* vertex, void (func)(const vertex_of_graph&)) const;
};

#endif//GRAPH_H