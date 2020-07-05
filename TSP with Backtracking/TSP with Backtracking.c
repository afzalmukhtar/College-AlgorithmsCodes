#include <stdbool.h>
#include <stdlib.h>
#include "tsp.h"

#define minimum(a, b) (((a) > (b)) ? b : a)

int *minPath, *tempPath;

int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost)
{

	if (currentCost > minCost)
		return minCost;
	
	if (nodesVisited == n && graph[v][0])
	{
		currentCost += graph[v][0];
		if(minCost > currentCost)
		{
			for (int k = 0; k < n; k++)
				minPath[k] = tempPath[k];
			minCost = currentCost;
		}
		return minCost;
	}
	
	else
	{	
		for (int i = 0; i < n ; i++)
			if (!visited[i])
			{
				visited[i] = true;
				tempPath[nodesVisited] = i;

				minCost = tspBacktrackRecursive(i, n, graph, visited, nodesVisited + 1, 
												currentCost + graph[v][i], minCost);
				visited[i] = false;
				tempPath[nodesVisited] = 0;
			}
	}
	
	return minCost;
}


int tspBackTrack(int n, int graph[][n])
{
	extern int *minPath, *tempPath;
	minPath = malloc(sizeof(int) * n);
	tempPath = malloc(sizeof(int) * n);
	
	bool visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	visited[0] = true;
	return tspBacktrackRecursive(0, n, graph, visited, 1, 0, __INT_MAX__);
}

int *printPath(int n, int graph[][n])
{
	tspBackTrack(n, graph);
	return minPath;
}
