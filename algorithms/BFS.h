#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* parent;
    vector<Path> next;
    int mindistance = INT_MAX;
};

template<typename T>
struct Path{
    int weight;
    Node<T>* destination;
};

template<typename T>
vector<Node<T>*> getShortestPath(Node<T>* start, Node<T>* end){
    if(!start) return;
    start->mindistance = 0;
}

template<typename T>
void BFS(Node<T>* node){
    if(!node) return;
    for(auto&i : node.next){
        if(node->mindistance + i.weight < i.destination){
            i.destination->parent = node;
            i.mindistance = node->mindistance + i.weight;
            BFS(i.destination);
        }
    }
}

