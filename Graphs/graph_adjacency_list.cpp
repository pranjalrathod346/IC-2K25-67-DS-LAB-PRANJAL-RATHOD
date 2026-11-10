
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<int> adj[20];

public:
    Graph(int v) {
        vertices = v;
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";

            for (int j : adj[i]) {
                cout << j << " ";
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
