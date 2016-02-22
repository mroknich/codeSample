// CSE 101 Winter 2016, PA 2
//
// Name: Horea Porutiu, Matthew Roknich
// PID: A97068584, A11323601
// Sources of Help: Tutors, TAs, Lectures, c++website
// Due: February 5th, 2016 at 11:59 PM

#ifndef __FOREX_CPP__
#define __FOREX_CPP__

#include <list>
#include <iostream>
#include "Graph.hpp"
#include "Forex.hpp"
#include <limits.h>
#include <queue>
#include <string>

using namespace std;

bool bellmanFord(Graph<std::string> &g, string src, string dest) {

      string destination;
      queue<string> nonRelaxed;
      float weight = 0;
      float v1, v2;
//set distances and visited to false
    for (auto it = g.vertices.begin(); it!= g.vertices.end(); it++) {
      for(auto it1 = g.vertices.begin(); it1!= g.vertices.end(); it1++){
          it1->second->distance = 0;
          it1->second->visited = false;
      }
      //set source to distance 1, push src
        g.vertices[it->first]->distance = 1;
        nonRelaxed.push(it->first);

        while(!nonRelaxed.empty()){
          //get the src vertex
          string current = nonRelaxed.front();
          nonRelaxed.pop();
          //if already visited, break out of loop
          if (g.vertices[current]->visited){
            continue;
          }
          //set visited to true
          g.vertices[current]->visited = true;
          //go through all of the edges of the current vertex
          for (auto edgeIt = g.vertices[current]->edges.begin();
            edgeIt!= g.vertices[current]->edges.end(); edgeIt++ ){
          //set destination vertex
            destination = *edgeIt;

            weight = g.get_weight(current, destination);
          //get current distance for the two verticies connected by edge
             v1 = g.vertices[current]->distance;
             v2 = g.vertices[destination]->distance;
          //update distance
            if ((v1*weight) > v2){
              g.vertices[destination]->distance = v1*weight;
              //only visit next vertex if it visited = false

            }
            if (!g.vertices[destination]->visited){
              nonRelaxed.push(destination);
            }
          }
        }
        //check for profit
        if (it->second->distance > 1){
          return true;
        }
      }//return false if we go through all verticies
      return false;
    }

bool forex(std::list<Ticker> tickers){


  	// Construct a graph using the tickers objects.
  	Graph<std::string> g;
  	std::string v1;
  	std::string v2;
    float w;

  	for (auto it = tickers.begin(); it != tickers.end(); ++it) {

  		v1 = it->in;
  		v2 = it->out;
  		w = it->rate;

  		if (g.vertices.count(v1) == 0) {
                  g.vertices[v1] = new Vertex<string>(v1);
          }
          if (g.vertices.count(v2) == 0) {
                  g.vertices[v2] = new Vertex<string>(v2);
          }

          g.vertices[v1]->edges.insert(v2);
          g.set_weight(v1, v2, w);
  	}
    return bellmanFord(g,v1,v2);
}
#endif
