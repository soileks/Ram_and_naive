#include"task3.h"

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
}