#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_mat.h"

#define SIZE 10


// check if there is a path
void hasPath(int matrix[SIZE][SIZE], int start, int end) {
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
                    return printf("True\n");
                    
                }
            }
        }
    }

    // No path found
    return printf("False\n");
}



int minDistance(int dist[], bool sptSet[], int vertices) {
    int minDist = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!sptSet[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int dijkstra(int graph[][SIZE], int src, int dest) {
    int dist[SIZE];
    bool sptSet[SIZE];

    for (int i = 0; i < SIZE; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dist, sptSet, SIZE);
        sptSet[u] = true;

        for (int v = 0; v < SIZE; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return (dist[dest] == INT_MAX || dist[dest] == 0) ? -1 : dist[dest];
}



void inputMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void functionA(int matrix[10][10]) {
    inputMatrix(matrix);
}

void functionB(int matrix[10][10]) {
     int i, j;
    scanf("%d %d", &i, &j);
    hasPath(matrix, i, j);
}

void functionC(int matrix[10][10]) {
    int i ,j;
    scanf("%d %d", &i, &j);
   int d = dijkstra(matrix, i, j);
   printf("%d\n", d);
}
