#pragma once
#include"task1.h"

void task2() {
    int n, m;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    cout << "Введите количество рёбер графа: ";
    cin >> m;
    vector<int> comp1(n);//для 1-го алгоритма
    vector<int> comp2(n);//для 2-го
    vector<int> P(n);
    //Генерация случайного графа
    vector<vector<int>> E(m, vector<int>(2));
   

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
    double time_naive = 0;//Время работы алг-ма наивный
    double time_RAM = 0;//Время работы алг-ма Рэма

    //вызов наивного алгоритма
    auto start = chrono::high_resolution_clock::now();
    component_naive(comp1, E, n, m);
    auto end = chrono::high_resolution_clock::now();

    time_naive = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "Массив comp при использовании наивного алгоритма:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp1[i] << " ";
    }
    cout << endl;
    cout << "Время работы наивного алгоритма: " << time_naive << " mks" << endl;

    //вызов алгоритма Рэма
    start = chrono::high_resolution_clock::now();
    array_RAM(comp2, E, n, m, P);
    end = chrono::high_resolution_clock::now();

    time_RAM = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "Массив comp при использовании алгоритма Рэма:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp2[i] << " ";
    }
    cout << endl;
    cout << "Время работы алгоритма Рэма: " << time_RAM << " mks" << endl;

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