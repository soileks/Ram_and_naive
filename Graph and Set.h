#pragma once

#include<vector>
#include<iostream>

using namespace std;

class Set;

class Graph {
    int n;
    int m;
    vector<vector<int>> E;

public:

    vector<vector<int>> Generate_graph(int _n, int _m);

    void print_graph();

};

class Set {
    vector<int> col;

public:
    Set(int n);

    void create(int x);
    
    int search(int x);

    void join(int x, int y);

    void Reinitialization(vector<int> _c);

};
