<<<<<<< HEAD
﻿#include"task3.h"
#include<fstream>
//#include<chrono>
namespace sc = std::chrono;
//using namespace std;

void task3() {
    vector<double> time_naive;//время работы наивного алгоритма 

    vector<double> time_RAM;//время работы алгоритма Рэма на массиве

    int time_size = 0;
    int m;
    int n;
    vector<int> comp1;
    vector<int> comp2;
    Graph g;

    

    for (int i = 1; i <= 1002; i += 10) {
        n = i;

         // m = n - 1;
        m = n * n / 10;
       // m = log2(n);

        vector<int> com1(n);
        vector<int> com2(n);
       // vector<int> c(n);
        comp1 = com1;//для 1-го алгоритма
        comp2 = com2;//для 2-го
       // s.Reinitialization(c);
        Set s(n);
        //вызов наивного алгоритма

        vector<vector<int>> E = g.Generate_graph(n, m);

        auto start = chrono::high_resolution_clock::now();

        component_naive(comp1, E, n, m);
        auto end = chrono::high_resolution_clock::now();

        time_naive.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());


        //вызов алгоритма Рэма
        start = chrono::high_resolution_clock::now();

        array_RAM(comp2, E, n, m,s);
        end = chrono::high_resolution_clock::now();
        time_RAM.push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());
        time_size += 1;
        cout << time_size << " ";
    }
    ofstream fout;
    fout.open("result1.txt");
    fout << time_size;
    fout << "\n";
    //fout << "Время работы наивного алгоритма для m = n - 1:\n";
   // fout << "Время работы наивного алгоритма для m = m = n * n / 10:\n";
   // fout << "Время работы наивного алгоритма для  m = log2(n):\n";
    for (int i = 0; i < time_size;i++) {
    fout << time_naive[i];
    fout << "\n";
    }
   // fout << "$";
    fout.close();
    ofstream fout2;
    fout2.open("result2.txt");
    fout2 << time_size;
    fout2 << "\n";
    //fout2 << "Время работы алгоритма Рэма для m = n - 1:\n";
   // fout2 << "Время работы алгоритма Рэма для m = m = n * n / 10:\n";
    //fout2 << "Время работы алгоритма Рэма для  m = log2(n):\n";
    for (int i = 0; i < time_size; i++) {
        fout2 << time_RAM[i];
        fout2 << "\n";
    }
   // fout2 << "$";
    fout2.close();
=======
﻿#include"task3.h"

void task3() {
    vector<double> time_naive;//время работы наивного алгоритма 

    vector<double> time_RAM;//время работы алгоритма Рэма на массиве

    int time_size = 0;
    int m;
    int n;
    vector<int> comp1;
    vector<int> comp2;
    Graph g;

    

    for (int i = 1; i <= 1002; i += 10) {
        n = i;

        //  m = n - 1;
        //  m = n * n / 10;
        m = log2(n);

        vector<int> com1(n);
        vector<int> com2(n);
       // vector<int> c(n);
        comp1 = com1;//для 1-го алгоритма
        comp2 = com2;//для 2-го
       // s.Reinitialization(c);
        Set s(n);
        //вызов наивного алгоритма

        vector<vector<int>> E = g.Generate_graph(n, m);

        double start = clock();

        component_naive(comp1, E, n, m);

        time_naive.push_back((clock() - start) / (double)CLOCKS_PER_SEC);


        //вызов алгоритма Рэма
        start = clock();

        array_RAM(comp2, E, n, m,s);
        time_RAM.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
        time_size += 1;
        cout << time_size << " ";
    }
>>>>>>> 4813527061de25587bce4a81bb64a984119acfc5
}