#include"Graph and Set.h"

vector<vector<int>> Graph::Generate_graph(int _n, int _m) {
    m = _m;
    n = _n;
    //��������� ���������� �����
    vector<vector<int>> e(m, vector<int>(2));
    E = e;

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

    return E;
}

void Graph:: print_graph() {
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

Set::Set(int n) {

    vector<int> _c(n);
    col = _c;
}

void Set:: create(int x) { //col ��� ���������

    col[x] = x;
}
int Set:: search(int x) {
    return col[x];
}

void Set:: join(int x, int y) {
    int z = min(x, y);
    for (int i = 0; i < col.size(); i++) {
        if (col[i] == x || col[i] == y) {
            col[i] = z;//�������������� ���������
        }
    }
}
void Set:: Reinitialization(vector<int> _c) {
    col = _c;
}
