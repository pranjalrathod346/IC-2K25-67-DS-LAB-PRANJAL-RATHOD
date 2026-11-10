
#include <iostream>
using namespace std;

class Graph {
    int vertices;
    int adj[20][20];

public:
    Graph(int v) {
        vertices = v;

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    if (v <= 0 || v > 20) {
        cout << "Invalid number of vertices!\n";
        return 0;
    }

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v;

        cout << "Enter edge (source destination): ";
        cin >> u >> v;

        g.addEdge(u, v);
    }

    g.display();

    return 0;
}
