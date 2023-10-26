#include"Graph and Set.h"


vector<vector<int>> Graph::Generate_graph(int _vertex, int _edge) {
    edge = _edge;
    vertex = _vertex;
    //Генерация случайного графа
    vector<vector<int>> e(edge, vector<int>(2));
    set_edge = e;
    srand(time(NULL));

    for (int j = 0; j < edge; j++) {
        int a = rand() % vertex;
        int b = rand() % vertex;
        //Обеспечивает, чтобы рёбра не повторялись
        while (find(set_edge.begin(), set_edge.end(), vector<int>{a, b}) != set_edge.end() || find(set_edge.begin(), set_edge.end(), vector<int>{b, a}) != set_edge.end() || a == b) {//find возвращает указатель на конец, если не нашли
            a = rand() % vertex;
            b = rand() % vertex;
        }
        set_edge[j] = { a, b };
    }

    return set_edge;
}

void Graph:: print_graph() {
    //Вывод графа в виде матрицы смежности
    if (vertex <= 10) {
        cout << "Граф задан матрицей смежности:" << endl;
        vector<vector<int>> matrix(vertex, vector<int>(vertex));
        
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < edge; i++) {
            matrix[set_edge[i][0]][set_edge[i][1]] = 1;
            matrix[set_edge[i][1]][set_edge[i][0]] = 1;
        }
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;

        }
    }
}

Set::Set(int vertex) {

    vector<int> _c(vertex);
    col = _c;
}

void Set:: create(int x) { //col это коллекция

    col[x] = x;
}
int Set:: search(int x) {
    return col[x];
}

void Set:: join(int x, int y) {
    int z = min(x, y);
    for (int i = 0; i < col.size(); i++) {
        if (col[i] == x || col[i] == y) {
            col[i] = z;//принадлежность множеству
        }
    }
}
void Set:: Reinitialization(vector<int> _c) {
    col = _c;
}
