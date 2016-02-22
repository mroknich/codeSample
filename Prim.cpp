// CSE 101 Winter 2016, PA 2
//
// Name: Matthew Roknich & Horea Porutiu
// PID: A11323601 & A97068584
// Sources of Help: Wikipedia
// Due: February 5th, 2016 at 11:59 PM

#ifndef __PRIM_CPP__
#define __PRIM_CPP__

#include "Graph.hpp"
#include <queue>
#include <utility>
#include <iostream>
#include <stdlib.h>  
#include <limits>
using namespace std;
// include more libraries as needed

template <class T>
class comparator {
public:
    // return true if left < right
    bool operator()(const std::pair<T, float> &left,
    const std::pair<T, float> &right) {

        if(left.second > right.second ) {
        	return true;
        }
        return false;
    }
};    


template <class T>
float prim(Graph<T>& g, T src) {
   float cost = 0.0;
    int last;

    // Initalize a priority queue Q
    std::priority_queue<std::pair<T, float>, 
    	std::vector<std::pair<T, float>>, 
    	comparator<T>> minQ;

    g.vertices[src]->distance = 0;

    
    minQ.push(std::make_pair(src,g.vertices[src]->distance));

  
    // While Q is not empty
    while (!minQ.empty()) {

    	// u = node in Q with smallest dist[]
    	std::pair<T,float> u = minQ.top();
    	//cout << u.first << endl;
    	minQ.pop();

    	g.vertices[u.first]->visited = true;
    	
    	// for each neighbor v of u
    	for (auto it = g.vertices[u.first]->edges.begin(); it != g.vertices[u.first]->edges.end(); ++it) {

    		// alt = dist[u] + dis_between (u,v)
    		float alt = g.get_weight(u.first,*it);
    		// if alt < dis[v]
    		if (alt < g.vertices[*it]->distance && g.vertices[*it]->visited != true) {
    			// dis[v] = alt
    			g.vertices[*it]->distance = alt;
    			g.vertices[*it]->prev = u.first;
    			// remove u from Q	
    			minQ.push(std::make_pair(*it, alt));

    		}
    	}

    }

    for(auto it = g.vertices.begin(); it != g.vertices.end(); ++it) 
    	cost+= it->second->distance;

    return cost;
}

#endif