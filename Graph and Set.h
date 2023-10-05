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
  


   vector<vector<int>> Generate_graph(int _n, int _m) {
        m = _m;
        n = _n;
        //Генерация случайного графа
        vector<vector<int>> e(m, vector<int>(2));
        E = e;

        for (int j = 0; j < m; j++) {
            int a = rand() % n;
            int b = rand() % n;
            //Обеспечивает, чтобы рёбра не повторялись
            while (find(E.begin(), E.end(), vector<int>{a, b}) != E.end() || find(E.begin(), E.end(), vector<int>{b, a}) != E.end() || a == b) {//find возвращает указатель на конец, если не нашли
                a = rand() % n;
                b = rand() % n;
            }
            E[j] = { a, b };
        }
        
        return E;
    }



    void print_graph() {
        //Вывод графа в виде матрицы смежности
        if (n <= 10) {
            cout << "Граф задан матрицей смежности:" << endl;
            int** matrix = new int* [n];
            for (int i = 0; i < n; i++)
                matrix[i] = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++) {
                matrix[E[i][0]][E[i][1]] = 1;
                matrix[E[i][1]][E[i][0]] = 1;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;

            }
        }
    }


};

class Set {
    vector<int> col;

public:
    Set(int n) {
        
        vector<int> _c(n);
        col = _c;
    }
    
    void create(int x) { //col это коллекция
        
        col[x] = x;
    }

    int search(int x) {
        return col[x];
    }

    void join(int x, int y) {
        int z = min(x, y);
        for (int i = 0; i < col.size(); i++) {
            if (col[i] == x || col[i] == y) {
                col[i] = z;//принадлежность множеству
            }
        }
    }
    void Reinitialization(vector<int> _c) {
        col = _c;
    }

};