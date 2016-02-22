// Tester for PA1 Forex
//
// DO NOT MODIFY

#ifndef __TEST_FOREX_CPP__
#define __TEST_FOREX_CPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

#include "TestGraph.hpp"
#include "Forex.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);
    std::list<Ticker> tickers;
    
    if (!buildTickers(tickers, input)) {
        std::cerr << "Unable to build graph, please check graph format" << std::endl;
        exit(1);
    }

    std::cout << "Trade status: " << forex(tickers) << std::endl;
    
    return 0;
}

#endif