class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, src, des):
        # Undirected Graph
        self.adjMatrix[src][des] = 1
        self.adjMatrix[des][src] = 1

    def print_graph(self):
        for row in self.adjMatrix:
            print(" ".join(map(str, row)))

    def DFS(self, vertex, visited):
        visited[vertex] = True
        print(vertex, end=" ")

        for i in range(self.vertices):
            if self.adjMatrix[vertex][i] == 1 and not visited[i]:
                self.DFS(i, visited)

    def BFS(self, vertex):
        visited = [False] * self.vertices
        queue = []
        visited[vertex] = True
        queue.append(vertex)

        while queue:
            curr = queue.pop(0)
            print(curr, end=" ")

            for i in range(self.vertices):
                if self.adjMatrix[curr][i] == 1 and not visited[i]:
                    visited[i] = True
                    queue.append(i)


if __name__ == "__main__":
    g = Graph(5)

    g.add_edge(0, 1)
    g.add_edge(0, 4)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 3)
    g.add_edge(3, 4)

    print("Adjacency Matrix Representation of the Graph")
    g.print_graph()

    print("\nDepth First Search: ", end="")
    visited = [False] * 5
    g.DFS(0, visited)

    print("\nBreadth First Search: ", end="")
    g.BFS(0)
