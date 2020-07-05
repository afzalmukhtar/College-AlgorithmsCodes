#include <stdlib.h>
#include <stdbool.h>
#include "graphSearch.h"
#include <stdio.h>
void dfs(int v, int n, int *visited, int *houses, int parent,const int graph[][n], int k)
{
	visited[v]++;
	(*houses)++;
	
	for(int i = 0; i < n; i++)
		if(abs(v - i) <= k)
		{
			if(graph[v][i] && visited[i] && i != parent)
				++visited[i];
			if(!visited[i] && graph[v][i])
				dfs(i, n, visited, houses, v, graph, k);
		}
}

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false
bool isTree(int n, const int graph[][n])
{
	int *visited = (int*) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	int houses = 0;
	dfs(0, n, visited, &houses, 0, graph, n);
	
	for(int i = 0; i < n; i++)
		if(visited[i] != 1)
			return false;
	return true;
	
}

// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n])
{
	return pepesAnswersWithK(n, safeSeq, n);
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
	Result r = {0, 0};
	int houses = 0;
	int *visited = (int*) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			houses = 0;
			dfs(i, n, visited, &houses, i, safeSeq, k);
			r.numDeliveryFrogs++;
		}
		if(houses > r.maxHouses)
			r.maxHouses = houses;
	}
	return r;
}









