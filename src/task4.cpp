#include"task4.h"

void task4() {

    vector<int> set_edges_for_out;
    int tmp = 0;
    for (int i = 1; i <= 1002; i += 10) {
        int vertex = i;
        int edge = 0;
        vector<int> comp(vertex);
        vector<int> comp_connected(vertex);
        Set s(vertex);
        vector<vector<int>> set_edge;
        array_RAM(comp, set_edge, vertex, edge,s);
        srand(time(NULL));
        while (comp != comp_connected) {
            edge++;
            int a = rand() % vertex;
            int b = rand() % vertex;
            while ((find(set_edge.begin(), set_edge.end(), vector<int>{a, b}) != set_edge.end()) || (find(set_edge.begin(), set_edge.end(), vector<int>{b, a}) != set_edge.end()) || (a == b)) {
                a = rand() % vertex;
                b = rand() % vertex;
            }
            set_edge.push_back({ a, b });
            array_RAM(comp, set_edge, vertex, edge,s);
        }
        set_edges_for_out.push_back(edge);
        cout << i << endl;
        cout << edge << endl;
        tmp++;
    }
}