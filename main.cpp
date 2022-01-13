#include <iostream>
#include "graph.h"

int main() {
    graph my_graph;
    for (int i = 0; i < 3; i++){
        my_graph.new_vertex();
    }
    std::string a = "hello";
    //my_graph[0][a] = 12;
    std::cout << my_graph[0][a];
    my_graph.new_edge(0,1);
    my_graph.new_edge(1,2);
    my_graph.new_edge(2,0);
    my_graph.delete_edge(1,0);
    my_graph.delete_vertex(0);
    my_graph.delete_vertex(1);
    my_graph.delete_vertex(2);
    std::cout << my_graph;
    return 0;
}