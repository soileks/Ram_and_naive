#pragma once
#include"task1.h"

void task2() {
    int n, m;
    cout << "������� ���������� ������ �����: ";
    cin >> n;
    cout << "������� ���������� ���� �����: ";
    cin >> m;
    Graph gr;
    vector<int> comp1(n);//��� 1-�� ���������
    vector<int> comp2(n);//��� 2-��

    vector<vector<int>> E = gr.Generate_graph(n, m);
    double time_naive = 0;//����� ������ ���-�� �������
    double time_RAM = 0;//����� ������ ���-�� ����

    //����� �������� ���������
    auto start = chrono::high_resolution_clock::now();
    component_naive(comp1, E, n, m);
    auto end = chrono::high_resolution_clock::now();

    time_naive = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "������ comp ��� ������������� �������� ���������:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp1[i] << " ";
    }
    cout << endl;
    cout << "����� ������ �������� ���������: " << time_naive << " mks" << endl;

    //����� ��������� ����
    start = chrono::high_resolution_clock::now();
    array_RAM(comp2, E, n, m);
    end = chrono::high_resolution_clock::now();

    time_RAM = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "������ comp ��� ������������� ��������� ����:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp2[i] << " ";
    }
    cout << endl;
    cout << "����� ������ ��������� ����: " << time_RAM << " mks" << endl;

    gr.print_graph();

   
}