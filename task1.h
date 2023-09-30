#pragma once
#include<iostream>
#include<math.h>
#include <time.h>
#include <random>
#include<chrono>
#include <vector>
#include <algorithm>

using namespace std;

void create(int x, vector<int>& P) { //– это коллекци€
    P[x] = x;
}

int search(int x, const vector<int>& P) {
    return P[x];
}

void join(int x, int y, vector<int>& P) {
    int z = min(x, y);
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == x || P[i] == y) {
            P[i] = z;//принадлежность множеству
        }
    }
}

void component_naive(vector<int>& comp, const vector<vector<int>>& E, int n, int m) {
    for (int i = 0; i < n; i++) {
        comp[i] = i;
    }
    for (int i = 0; i < n-1 ; i++) {//дл€ каждого ребра ищем минимум
        for (int j = 0; j < m; j++) {
            int q = min(comp[E[j][0]], comp[E[j][1]]);
            comp[E[j][0]] = q;
            comp[E[j][1]] = q;
        }
    }
}

void array_RAM(vector<int>& comp, const vector<vector<int>>& E, int n, int m, vector<int>& P) {
    for (int i = 0; i < n; i++) {
        create(i, P);
    }
    for (int i = 0; i < m; i++) {
        int n1 = search(E[i][0], P);
        int n2 = search(E[i][1], P);
        if (n1 != n2) {
            join(n1, n2, P);
        }
    }
    for (int i = 0; i < n; i++) {
        comp[i] = search(i, P);
    }
}






