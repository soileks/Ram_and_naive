#pragma once
#include"task1.h"

void task2() {
    int n, m;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    cout << "Введите количество рёбер графа: ";
    cin >> m;
    Graph gr;
    vector<int> comp1(n);//для 1-го алгоритма
    vector<int> comp2(n);//для 2-го

    vector<vector<int>> E = gr.Generate_graph(n, m);
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
    array_RAM(comp2, E, n, m);
    end = chrono::high_resolution_clock::now();

    time_RAM = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "Массив comp при использовании алгоритма Рэма:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp2[i] << " ";
    }
    cout << endl;
    cout << "Время работы алгоритма Рэма: " << time_RAM << " mks" << endl;

    gr.print_graph();

   
}