#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix = vector<vector<int>>(v, vector<int>(v, 0));
    }

    void addEdge(int src, int des) {
        // Undirected Graph
        adjMatrix[src][des] = 1;
        adjMatrix[des][src] = 1;
    }

    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void BFS(int vertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[vertex] = true;
        q.push(vertex);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix Representation of the Graph" << endl;
    g.printGraph();

    cout << "\nDepth First Search: ";
    vector<bool> visited(5, false);
    g.DFS(0, visited);

    cout << "\nBreadth First Search: ";
    g.BFS(0);

    return 0;
}
