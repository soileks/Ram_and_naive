#pragma once

#include<vector>
#include<iostream>
#include<ctime>

using namespace std;

class Set;

class Graph {
    int vertex;
    int edge;
    vector<vector<int>> set_edge;

public:

    vector<vector<int>> Generate_graph(int _vertex, int _edge);

    void print_graph();

};

class Set {
    vector<int> col;

public:
    Set(int vertex=1);

    void create(int x);
    
    int search(int x);

    void join(int x, int y);

    void Reinitialization(vector<int> _c);

};
