#pragma once
#include"task1.h"

void task3() {
    vector<double> time_naive;//����� ������ �������� ��������� 
    
    vector<double> time_RAM;//����� ������ ��������� ���� �� �������
    
    int time_size = 0;
    int m;
    int n;
    vector<int> comp1;
    vector<int> comp2;
    vector<int> P;
    for (int i = 1; i <= 1002; i += 10) {
        n = i;
        //  m = n - 1;
        //  m = n * n / 10;
        m = log2(n);
        vector<int> com1(n);
        vector<int> com2(n);
        vector<int> Pp(n);
        comp1 = com1;//��� 1-�� ���������
        comp2 = com2;//��� 2-��
        P = Pp;

        //��������� �����
        vector<vector<int>> E(m, vector<int>(2));

        for (int j = 0; j < m; j++) {
            int a = rand() % n;
            int b = rand() % n;
            //������������, ����� ���� �� �����������
            while (find(E.begin(), E.end(), vector<int>{a, b}) != E.end() || find(E.begin(), E.end(), vector<int>{b, a}) != E.end() || a == b) {//find ���������� ��������� �� �����, ���� �� �����
                a = rand() % n;
                b = rand() % n;
            }
            E[j] = { a, b };
        }
        //����� �������� ���������
        double start = clock();
       
        component_naive(comp1, E, n, m);
        
        time_naive.push_back((clock() - start) / (double)CLOCKS_PER_SEC);

        
         //����� ��������� ����
        start = clock();
        
        array_RAM(comp2, E, n, m, P);
       time_RAM.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
        time_size += 1;
        cout << time_size << " ";
    }
}