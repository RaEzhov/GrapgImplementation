#include <iostream>
#include "graph.h"

int main() {
    graph my_graph;
    for (int i = 0; i < 10; i++){
        my_graph.newVertex();
    }
    my_graph.newVertex({0,1,2,3,4,5,6,7,8,9});
    my_graph.newEdge(1,3);
    my_graph.newEdge(2,3);
    my_graph.newEdge(1,9);
    std::cout << my_graph;
    return 0;
}