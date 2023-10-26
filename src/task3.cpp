#include"task3.h"
#include<fstream>
//#include<chrono>
namespace sc = std::chrono;
//using namespace std;

void task3() {
    vector<double> time_naive;//время работы наивного алгоритма 

    vector<double> time_RAM;//время работы алгоритма Рэма на массиве

    int time_size = 0;
    int edge;
    int vertex;
    vector<int> comp1;
    vector<int> comp2;
    Graph g;

    Set s;
    int o;
    cout << "Выбери: 1)m = n - 1 , 2)m = n * n / 10 , 3)m = log2(n) \n";
    cin >> o;

    for (int i = 1; i <= 1002; i += 10) {
        vertex = i;

        switch (o) {
        case 1: edge = vertex - 1;
        case 2:edge = vertex * vertex / 10;
        case 3: edge = log2(vertex);
        }
        vector<int> com1(vertex);
        vector<int> com2(vertex);
        vector<int> c(vertex);
        comp1 = com1;//для 1-го алгоритма
        comp2 = com2;//для 2-го
        s.Reinitialization(c);
       
        //вызов наивного алгоритма

        vector<vector<int>> set_edge = g.Generate_graph(vertex, edge);

        auto start = chrono::high_resolution_clock::now();

        component_naive(comp1, set_edge, vertex, edge);
        auto end= chrono::high_resolution_clock::now();

        time_naive.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());
        //вызов алгоритма Рэма
        start = chrono::high_resolution_clock::now();

        array_RAM(comp2, set_edge, vertex, edge,s);
        end = chrono::high_resolution_clock::now();
        time_RAM.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());
        time_size += 1;
        cout << time_size << " ";
        
    }
    ofstream fout;
    fout.open("result1.txt");
    fout << time_size;
    fout << "\n";
    
    for (int i = 0; i < time_size;i++) {
    fout << time_naive[i];
    fout << "\n";
    }
  
    fout.close();
    ofstream fout2;
    fout2.open("result2.txt");
    fout2 << time_size;
    fout2 << "\n";
    
    for (int i = 0; i < time_size; i++) {
        fout2 << time_RAM[i];
        fout2 << "\n";
    }
  
    fout2.close();
}