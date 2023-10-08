#pragma once

//#include<iostream>
#include<math.h>
#include <time.h>
#include <random>
#include<chrono>
//#include <vector>
#include <algorithm>
#include"Graph and set.h"

using namespace std;

void component_naive(vector<int>& comp, const vector<vector<int>>& E, int n, int m);
void array_RAM(vector<int>& comp, const vector<vector<int>>& E, int n, int m,Set s);

