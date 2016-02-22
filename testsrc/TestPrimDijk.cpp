// Tester for PA2 PrimDijk
//
// DO NOT MODIFY

#ifndef __TEST_PRIM_DIJK_CPP__
#define __TEST_PRIM_DIJK_CPP__

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "TestGraph.hpp"
#include "PrimDijk.hpp"

int main(int argc, char * argv[]) {
    if (argc != 3) {
        std::cerr << "Invalid number of arguments; expecting input file name, then c-value" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);
    float c = atof(argv[2]);

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

    std::cout << "The cost of Prim-Dijk with c=" << c << " is: " << primdijk(g, src, c) << std::endl;
    
    return 0;
}

#endif