// CSE 101 Winter 2016, PA 2
//
// Name: Matthew Roknich & Horea Porutiu
// PID: A11323601 & A97068584
// Sources of Help: Lecture Slides + Wikipedia
// Due: February 5th, 2016 at 11:59 PM

#ifndef __DIJKSTRA_CPP__
#define __DIJKSTRA_CPP__

#include "Graph.hpp"
#include <queue>
#include <utility>
#include <iostream>
#include <stdlib.h>  
#include <limits>
#include <stack>
using namespace std;
// include more libraries as needed

template <class T>
std::set<T> dfs(Graph<T>& g, T t){
    std::set<T> visited;
    std::stack<T> s;

    // push the starting vertex
    s.push(t); 
    while (!s.empty()) {

        Vertex<T> * current = g.vertices[s.top()];
        s.pop();

        auto search = visited.find(current->id);
        if (search != visited.end()) {
            continue;
        }
        visited.insert(current->id);
        
        for (auto it = current->edges.begin(); it != current->edges.end(); ++it) {
        // 'it' is a list<T> iterator that you can use (i.e. dereferencing it will give you the value of T)
            s.push(*it);
        }
    }

    return visited;
}	

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
float dijkstra(Graph<T>& g, T src) {
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
    	
    	// for each neighbor v of u
    	for (auto it = g.vertices[u.first]->edges.begin(); it != g.vertices[u.first]->edges.end(); ++it) {

    		// alt = dist[u] + dis_between (u,v)
    		float alt = g.vertices[u.first]->distance + g.get_weight(u.first,*it);
    		// if alt < dis[v]
    		if (alt < g.vertices[*it]->distance) {
    			// dis[v] = alt
    			g.vertices[*it]->distance = alt;

    			g.vertices[*it]->prev = u.first;

    			minQ.push(std::make_pair(*it, alt));

    			// remove u from Q		
    		}
    	}

    }

    // accumulate cost
    std::stack<T> s;
    s.push(src);
    T id;
    while (!s.empty()) {
    	id = s.top();
    	s.pop();

    	auto itr = g.vertices[id]->edges.begin();
    	while (itr != g.vertices[id]->edges.end()) {
    		if (g.vertices[*itr]->prev == id) {
    			cost += g.get_weight(*itr,id);
    			s.push(*itr);
    		}
    		++itr;
    	}
    	
    }

    return cost;
}

#endif