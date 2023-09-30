#pragma once
#include"task1.h"

void task2() {
    int n, m;
    cout << "������� ���������� ������ �����: ";
    cin >> n;
    cout << "������� ���������� ���� �����: ";
    cin >> m;
    vector<int> comp1(n);//��� 1-�� ���������
    vector<int> comp2(n);//��� 2-��
    vector<int> P(n);
    //��������� ���������� �����
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
    array_RAM(comp2, E, n, m, P);
    end = chrono::high_resolution_clock::now();

    time_RAM = chrono::duration_cast<chrono::microseconds>(end - start).count();
    

    cout << "������ comp ��� ������������� ��������� ����:" << endl;
    for (int i = 0; i < n; i++) {
        cout << comp2[i] << " ";
    }
    cout << endl;
    cout << "����� ������ ��������� ����: " << time_RAM << " mks" << endl;

    //����� ����� � ���� ������� ���������
    if (n <= 10) {
        cout << "���� ����� �������� ���������:" << endl;
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