#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

// Function to create a graph with the given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    
    // Initialize vertices and edges to 0
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->edges[src][dest] = 1;
        graph->edges[dest][src] = 1;
        graph->numEdges++;
    }
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Vertices: ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", graph->vertices[i]);
    }
    printf("\n");
    
    printf("Edges:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    
    return 0;
}