// Write a C program to implement the Depth-First Search (DFS) algorithm on a graph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

// Graph structure with adjacency matrix
struct Graph {
    int adj[MAX][MAX];
    int numVertices;
};

// Function to initialize the graph
void initGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;  // No edge
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;  // For undirected graph
}

// DFS algorithm
void dfs(struct Graph* g, int vertex, bool visited[]) {
    // Mark the current node as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all the adjacent vertices
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, src, dest;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Read edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    // Array to keep track of visited nodes
    bool visited[MAX] = {false};

    // Perform DFS starting from vertex 0
    printf("Depth-First Search starting from vertex 0:\n");
    dfs(&g, 0, visited);
    
    return 0;
}