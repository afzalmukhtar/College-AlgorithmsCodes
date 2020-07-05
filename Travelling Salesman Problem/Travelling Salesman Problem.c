#include <stdio.h>
#include <stdlib.h>
#include "tsp.h"
#include <string.h>

int *minPath;

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n])
{
	//Initialization of all values
	int *permutation = malloc(sizeof(int)*n);
	minPath = malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		permutation[i] = i;

	int minCost = getCost(n, graph, permutation);
	memcpy(minPath, permutation, n*sizeof(int));
	//End of initialization
	
	//Get cost for different permutations
	while(get_next_permutation(permutation, n))
	{
		int Cost = getCost(n, graph, permutation);
		if(Cost < minCost)
		{
			minCost = Cost;
			memcpy(minPath, permutation, n*sizeof(int));
		}
	}
	//End of getting cost
	return minCost;
}

// Returns an array of size n, 
// starting at city_0 (that is the first node) 
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n])
{
	tsp(n, graph);
	return minPath;	
}

// Given a permutation of path - P[], 
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P)
{
	int i, cost = 0;
	
	for(i = 0; i < n - 1; i++)	//Cost from 0 to n-1
		cost += graph[P[i]][P[i + 1]]; 
	cost += graph[P[n - 1]][P[0]];	//Returning cost from n-1 to 0
	return cost;
}

