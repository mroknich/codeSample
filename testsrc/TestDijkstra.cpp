// Tester for PA1 Dijkstra's
//
// DO NOT MODIFY

#ifndef __TEST_DIJKSTRA_CPP__
#define __TEST_DIJKSTRA_CPP__

#include <iostream>
#include <fstream>

#include "TestGraph.hpp"
#include "Dijkstra.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);

    // grab the target starting vertex
    int src;
    std::string vString;
    if (getline(input, vString)) {
        std::stringstream vStream(vString);
        vStream >> src; 
    }
    else {
        std::cerr << "Unable to open file '" << argv[1] << "'" << std::endl;
        exit(1);
    }

    Graph<int> g;
    
    if (!buildGraph(g, input, true)) {
        std::cerr << "Unable to build graph, please check graph format" << std::endl;
        exit(1);
    }

    std::cout << "The shortest-paths tree cost is: " << dijkstra(g, src) << std::endl;
    
    return 0;
}

#endif