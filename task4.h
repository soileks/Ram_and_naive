#pragma once
#include"task1.h"
void task4() {

        vector<int> M;
        int tmp = 0;
        for (int i = 1; i <= 1002; i += 10) {
            int n = i;
            int m = 0;
            vector<int> comp(n);
            vector<int> comp_connected(n);
            vector<int> P(n);
            vector<vector<int>> E;
            array_RAM(comp, E, n, m, P);
            while (comp != comp_connected) {
                m++;
                int a = rand() % n;
                int b = rand() % n;
                while ((find(E.begin(), E.end(), vector<int>{a, b}) != E.end()) || (find(E.begin(), E.end(), vector<int>{b, a}) != E.end()) || (a == b)) {
                    a = rand() % n;
                    b = rand() % n;
                }
                E.push_back({ a, b });
                array_RAM(comp, E, n, m, P);
            }
            M.push_back(m);
           cout << i << endl;
            cout << m << endl;
            tmp++;
        }
}