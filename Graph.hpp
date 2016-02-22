// DO NOT MODIFY
//
// CSE 101 Winter 2016, PA 2

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <cfloat>

#include <iostream>

struct Ticker {
    Ticker(std::string in, std::string out, float rate){
        this->in = in;
        this->out = out;
        this->rate = rate;
    }
    std::string in;
    std::string out;
    float rate;
};

template <class T>
class Vertex {
public:

    Vertex(T id, float default_distance = FLT_MAX){
        this->id = id;
        this->visited = false;
        this->distance = default_distance;
    }
    
    T id;
    bool visited;
    float distance;
    T prev;
    std::set<T> edges;
};

template <class T>
class Edge {
public:
    T src;
    T dest;

    Edge(T s, T d){
        this->src = s;
        this->dest = d;
    }

    bool operator<(const Edge<T>& l) const{
        return (l.src < this->src) || 
               ((l.src == this->src) && (l.dest < this->dest));
    }
};

template <class T>
class Graph {
public:
    std::unordered_map<T, Vertex<T> *> vertices;
    std::map<Edge<T>, float> weights;

    // Getter function for getting the weight of an edge
    float get_weight(T src, T dest);
    // Setter function for setting the weight of an edge
    void set_weight(T src, T dest, float weight);
};

template <class T>
float Graph<T>::get_weight(T src, T dest){
    return weights[Edge<T>(src, dest)];
}

template <class T>
void Graph<T>::set_weight(T src, T dest, float weight){
    weights[Edge<T>(src, dest)] = weight;
}

#endif