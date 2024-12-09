// Write a C program to implement the Breadth-First Search (BFS) algorithm on a graph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

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

// BFS algorithm
void bfs(struct Graph* g, int startVertex) {
    struct Queue q;
    initQueue(&q);

    bool visited[MAX] = {false};  // Array to track visited vertices

    // Start by marking the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        // Explore all neighbors of the current vertex
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
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

    // Perform BFS starting from vertex 0
    bfs(&g, 0);

    return 0;
}