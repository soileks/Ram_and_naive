#include"task1.h"

void component_naive(vector<int>& comp, const vector<vector<int>>& E, int n, int m) {
    for (int i = 0; i < n; i++) {
        comp[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {//для каждого ребра ищем минимум
        for (int j = 0; j < m; j++) {
            int q = min(comp[E[j][0]], comp[E[j][1]]);
            comp[E[j][0]] = q;
            comp[E[j][1]] = q;
        }
    }
}
void array_RAM(vector<int>& comp, const vector<vector<int>>& E, int n, int m, Set s) {
    
    for (int i = 0; i < n; i++) {
        s.create(i);
    }
    for (int i = 0; i < m; i++) {
        int n1 = s.search(E[i][0]);
        int n2 = s.search(E[i][1]);
        if (n1 != n2) {
            s.join(n1, n2);
        }
    }
    for (int i = 0; i < n; i++) {
        comp[i] = s.search(i);
    }

}