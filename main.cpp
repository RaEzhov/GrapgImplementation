#include <iostream>
#include "graph.h"

int main() {
    graph my_graph;
    my_graph.newVertex();
    std::cout << my_graph;
    my_graph.newVertex({0});

    std::cout << my_graph;
    return 0;
}