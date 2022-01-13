#include <iostream>
#include "graph.h"

int main() {
    graph my_graph;
    for(int i = 0; i < 11; i++){
        my_graph.new_vertex();
    }
    my_graph.new_edge({{10, 9},
                       {9,  8},
                       {8,  7},
                       {7,  2},
                       {9,  6},
                       {6,3},
                       {3,1},
                       {9,5},
                       {5,4}
                      });
    my_graph.delete_vertex(0);
    std::cout << my_graph;
    my_graph.breadth_first_search([](const vertex_of_graph& v){std::cout << v.id() << ' ';});
    std::cout << '\n';
    my_graph.depth_first_search([](const vertex_of_graph& v){std::cout << v.id() << ' ';});
    return 0;
}