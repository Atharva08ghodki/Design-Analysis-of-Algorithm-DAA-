#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = vertex;
    newNode->next = NULL;
	return newNode;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    //write your code here...
    Node* newNode = createNode(v);

    // Add node at the beginning of the adjacency list
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    //write your code here...
    for (int i = 0; i < V; i++) {
        Node* current = adjList[i];

        while (current != NULL) {
            Node* minNode = current;
            Node* temp = current->next;

            // Find the smallest vertex
            while (temp != NULL) {
                if (temp->vertex < minNode->vertex) {
                    minNode = temp;
                }
                temp = temp->next;
            }

            // Swap vertex values
            int t = current->vertex;
            current->vertex = minNode->vertex;
            minNode->vertex = t;

            current = current->next;
        }
	}
}

// Depth-First Search (DFS) function
void DFS(int start) {
    //write your code here...
    visited[start] = 1;

    // Print the current vertex
    printf("%d ", start);

    Node* current = adjList[start];

    while (current != NULL) {
        if (!visited[current->vertex]) {
            DFS(current->vertex);
        }

        current = current->next;
	}
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
