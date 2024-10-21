#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int vertices;
    int adjMatrix[5][5];
};

// Function to create a Graph
struct Graph* create(int vertices) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->vertices = vertices;

    // Initializing the adjacency matrix
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }

    return g;
}

void edge(struct Graph* g, int src, int des) {
    // Directed Graph
    // g->adjMatrix[src][des] = 1;

    // Uncomment for Undirected Graph
    g->adjMatrix[src][des] = 1;
    g->adjMatrix[des][src] = 1;
}

// Function to display the adjacency matrix
void printGraph(struct Graph* g) {
    for(int i = 0; i < g->vertices; i++) {
        for(int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// DFS
void DFS(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(int i=0; i<g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// BFS
void BFS(struct Graph* g, int vertex) {
    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = -1;

    visited[vertex] = 1;
    queue[++rear] = vertex;

    while (front <= rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for(int i=0; i< g->vertices; i++) {
            if (g->adjMatrix[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            } 
        }
    }
}

void main() {
    struct Graph* g = create(5);

    // Adding the edges
    edge(g, 0, 1);
    edge(g, 0, 4);
    edge(g, 1, 3);
    edge(g, 1, 4);
    edge(g, 2, 3);
    edge(g, 3, 4);

    printf("Adjacency Matrix Representation of the Graph\n");
    printGraph(g);

    printf("\nDepth First Search (DFS) : ");
    int visited[5] = {0};
    DFS(g, 0, visited);

    printf("\nBreadth First Search (BFS) : ");
    BFS(g, 0);
}