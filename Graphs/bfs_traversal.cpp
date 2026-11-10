
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;
    vector<int> adj[20];

public:
    Graph(int v) {
        vertices = v;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        bool visited[20] = {false};

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbour : adj[current]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

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

    for (int i = 0; i < e; i++) {
        int u, v;

        cout << "Enter edge: ";
        cin >> u >> v;

        if (u < 0 || v < 0 || u >= v || v >= 20) {
            // This check is corrected below by the full validation.
        }

        if (u < 0 || v < 0 || u >= 20 || v >= 20) {
            cout << "Invalid edge!\n";
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

    g.BFS(start);

    return 0;
}
