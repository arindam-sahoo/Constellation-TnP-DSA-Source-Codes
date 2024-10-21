import java.util.LinkedList;
import java.util.Queue;

public class Graph {
    private int vertices;
    private int[][] adjMatrix;

    // Constructor
    public Graph(int vertices) {
        this.vertices = vertices;
        adjMatrix = new int[vertices][vertices];
    }

    public void addEdge(int src, int des) {
        // Undirected Graph
        adjMatrix[src][des] = 1;
        adjMatrix[des][src] = 1;
    }

    public void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void DFS(int vertex, boolean[] visited) {
        visited[vertex] = true;
        System.out.print(vertex + " ");

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    public void BFS(int vertex) {
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<>();
        visited[vertex] = true;
        queue.add(vertex);

        while (!queue.isEmpty()) {
            int curr = queue.poll();
            System.out.print(curr + " ");

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(5);

        g.addEdge(0, 1);
        g.addEdge(0, 4);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        g.addEdge(3, 4);

        System.out.println("Adjacency Matrix Representation of the Graph");
        g.printGraph();

        System.out.println("\nDepth First Search: ");
        boolean[] visited = new boolean[5];
        g.DFS(0, visited);

        System.out.println("\nBreadth First Search: ");
        g.BFS(0);
    }
}
