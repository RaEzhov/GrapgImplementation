#include <iostream>
#include "graph.h"

int main() {
    graph my_graph;
    for (int i = 0; i < 10; i++){
        my_graph.new_vertex();
    }
    my_graph.new_vertex({0,1,2,3,4,5,6,7,8,9});
    my_graph.new_edge(1,3);
    my_graph.new_edge(2,3);
    my_graph.new_edge(1,9);
    std::cout << my_graph;
    return 0;
}