
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<int> adj[20];
    bool visited[20];

    void DFSUtil(int vertex) {
        visited[vertex] = true;

        cout << vertex << " ";

        for (int neighbour : adj[vertex]) {
            if (!visited[neighbour]) {
                DFSUtil(neighbour);
            }
        }
    }

public:
    Graph(int v) {
        vertices = v;

        for (int i = 0; i < 20; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start) {
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        cout << "DFS Traversal: ";
        DFSUtil(start);
        cout << endl;
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

    if (e < 0 || e > v * (v - 1) / 2) {
        cout << "Invalid number of edges!\n";
        return 0;
    }

    for (int i = 0; i < e; i++) {
        int u, v;

        cout << "Enter edge: ";
        cin >> u >> v;

        if (u < 0 || v < 0 || u >= 20 || v >= 20 ||
            u >= v || v >= 20) {
            cout << "Invalid edge! Enter again.\n";
            i--;
            continue;
        }

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= v) {
        cout << "Invalid starting vertex!\n";
        return 0;
    }

    g.DFS(start);

    return 0;
}
