#include <stdio.h>
#define INF 99999 // Infinity
void floydWarshall(int graph[][4], int V) {
int dist[V][V], i, j, k;
for (i = 0; i < V; i++)
for (j = 0; j < V; j++)
dist[i][j] = graph[i][j];
for (k = 0; k < V; k++) {
for (i = 0; i < V; i++) {
// above picked source 
for (j = 0; j < V; j++) {
if (dist[i][k] + dist[k][j] < dist[i][j])
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}

printf("The following matrix shows the shortest distancesbetween every pair of vertices:\n");
for (i = 0; i < V; i++) {
for (j = 0; j < V; j++) {
if (dist[i][j] == INF)
printf("%7s", "INF"); 
else
printf("%7d", dist[i][j]);
}
printf("\n");
}
}
int main() {
int V = 4;

int graph[4][4] = {{0, 5, INF, 10},
{INF, 0, 3, INF},
{INF, INF, 0, 1},
{INF, INF, INF, 0}};
floydWarshall(graph, V);
 return 0;
}
