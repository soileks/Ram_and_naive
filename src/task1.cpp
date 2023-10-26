#include"task1.h"

void component_naive(vector<int>& comp, const vector<vector<int>>& set_edge, int vertex, int edge) {
    for (int i = 0; i < vertex; i++) {
        comp[i] = i;
    }
    for (int i = 0; i < vertex - 1; i++) {//для каждого ребра ищем минимум
        for (int j = 0; j < edge; j++) {
            int q = min(comp[set_edge[j][0]], comp[set_edge[j][1]]);
            comp[set_edge[j][0]] = q;
            comp[set_edge[j][1]] = q;
        }
    }
}
void array_RAM(vector<int>& comp, const vector<vector<int>>& set_edge, int vertex, int edge, Set s) {
    
    for (int i = 0; i < vertex; i++) {
        s.create(i);
    }
    for (int i = 0; i < edge; i++) {
        int n1 = s.search(set_edge[i][0]);
        int n2 = s.search(set_edge[i][1]);
        if (n1 != n2) {
            s.join(n1, n2);
        }
    }
    for (int i = 0; i < vertex; i++) {
        comp[i] = s.search(i);
    }

}