#include"task2.h"

void task2() {
    int vertex, edge;
    cout << "Введите количество вершин графа: ";
    cin >> vertex;
    cout << "Введите количество рёбер графа: ";
    cin >> edge;
    Graph gr;
    vector<int> comp1(vertex);//для 1-го алгоритма
    vector<int> comp2(vertex);//для 2-го
    Set s(vertex);
    vector<vector<int>> set_edge = gr.Generate_graph(vertex, edge);
    double time_naive = 0;//Время работы алг-ма наивный
    double time_RAM = 0;//Время работы алг-ма Рэма

    //вызов наивного алгоритма
    auto start = chrono::high_resolution_clock::now();
    component_naive(comp1, set_edge, vertex, edge);
    auto end = chrono::high_resolution_clock::now();

    time_naive = chrono::duration_cast<chrono::microseconds>(end - start).count();


    cout << "Массив comp при использовании наивного алгоритма:" << endl;
    for (int i = 0; i < vertex; i++) {
        cout << comp1[i] << " ";
    }
    cout << endl;
    cout << "Время работы наивного алгоритма: " << time_naive << " mks" << endl;

    //вызов алгоритма Рэма
    start = chrono::high_resolution_clock::now();
    array_RAM(comp2, set_edge, vertex, edge,s);
    end = chrono::high_resolution_clock::now();

    time_RAM = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Массив comp при использовании алгоритма Рэма:" << endl;
    for (int i = 0; i < vertex; i++) {
        cout << comp2[i] << " ";
    }
    cout << endl;
    cout << "Время работы алгоритма Рэма: " << time_RAM << " mks" << endl;

    gr.print_graph();

}

