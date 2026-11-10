
#include <iostream>
#include <vector>
#include <climits>
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

    void addEdge(int u, int v, int weight) {
        if (u < 0 || v < 0 ||
            u >= vertices || v >= vertices ||
            weight < 0) {
            cout << "Invalid edge or weight!\n";
            return;
        }

        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    void dijkstra(int source) {
        int distance[20];
        bool visited[20] = {false};

        for (int i = 0; i < vertices; i++) {
            distance[i] = INT_MAX;
        }

        distance[source] = 0;

        for (int count = 0; count < vertices; count++) {
            int u = -1;

            for (int i = 0; i < vertices; i++) {
                if (!visited[i] &&
                    (u == -1 || distance[i] < distance[u])) {
                    u = i;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (adj[u][v] > 0 && !visited[v] &&
                    distance[u] <= INT_MAX - adj[u][v] &&
                    distance[u] + adj[u][v] < distance[v]) {

                    distance[v] = distance[u] + adj[u][v];
                }
            }
        }

        cout << "\nShortest Distances from Source "
             << source << ":\n";

        cout << "Vertex\tDistance\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << "\t";

            if (distance[i] == INT_MAX)
                cout << "Unreachable";
            else
                cout << distance[i];

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

    if (e < 0 || e > v * (v - 1) / 2) {
        cout << "Invalid number of edges!\n";
        return 0;
    }

    for (int i = 0; i < e; i++) {
        int u, v, w;

        cout << "Enter source, destination and weight: ";
        cin >> u >> v >> w;

        if (u < 0 || v < 0 || u >= v ||
            v >= 20 || w < 0) {
            cout << "Invalid edge! Enter again.\n";
            i--;
            continue;
        }

        g.addEdge(u, v, w);
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    if (source < 0 || source >= v) {
        cout << "Invalid source!\n";
        return 0;
    }

    g.dijkstra(source);

    return 0;
}
