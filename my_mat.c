#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_mat.h"

#define SIZE 10


// build a random graph
void buildGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = rand() % 10;
        }
    }
}


// check if there is a path
bool hasPath(int matrix[SIZE][SIZE], int start, int end) {
    bool visited[SIZE] = {false};
    int queue[SIZE];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = queue[front++];
        for (int neighbor = 0; neighbor < SIZE; neighbor++) {
            if (matrix[current][neighbor] > 0 && !visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = true;
                if (neighbor == end) {
                    // Path found
                    return true;
                }
            }
        }
    }

    // No path found
    return false;
}


// print bfs
void printShortestPath(int matrix[SIZE][SIZE], int start, int end) {
    // Use BFS to find the shortest path
    int queue[SIZE];
    int parent[SIZE];
    bool visited[SIZE] = {false};
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = queue[front++];
        for (int neighbor = 0; neighbor < SIZE; neighbor++) {
            if (matrix[current][neighbor] > 0 && !visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = true;
                parent[neighbor] = current;
                if (neighbor == end) {
                    // Print the shortest path
                    printf("Shortest Path from %d to %d: %d ", start, end, end);
                    int node = end;
                    while (node != start) {
                        node = parent[node];
                        printf("<- %d ", node);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }

    // If no path found
    printf(-1);
}



// bfs
bool bfsShortestPath(int graph[SIZE][SIZE], int start, int end, int path[SIZE]) {
    bool visited[SIZE] = {false};
    int queue[SIZE];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = queue[front++];
        for (int neighbor = 0; neighbor < SIZE; neighbor++) {
            if (graph[current][neighbor] > 0 && !visited[neighbor]) {
                queue[rear++] = neighbor;
                path[neighbor] = current;
                visited[neighbor] = true;
                if (neighbor == end) {
                    return true;
                }
            }
        }
    }

    return false;
}



void inputMatrix(int matrix[10][10]) {
    printf("Enter values for the matrix (10x10):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void functionA(int matrix[10][10]) {
   
    printf("Executing function A\n");
    inputMatrix(matrix);
}

void functionB(int matrix[10][10]) {
     int i, j;
    printf("Enter two nodes (i j): ");
    scanf("%d %d", &i, &j);
    printf("Executing function B\n");
    hasPath(matrix, i, j);
}

void functionC(int matrix[10][10]) {
    int i ,j;
    printf("Executing function C\n");
    printf("Enter start and end nodes for shortest path (start end): ");
    scanf("%d %d", &i, &j);
    printShortestPath(matrix, i, j);
}
