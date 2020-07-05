#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "session12_WarshallsFloyds.h"


#define MIN(a, b) ( ((a) > (b)) ? b : a)
#define COMPUTE(a, b, c) ((a) || ((b) && (c)))
#define VALUE(a) ((a) == -1 ? 1000000 : a)


struct Graph
{
	int **W, **F;
	int W_order, F_order;
	double W_time, F_time;
}graph;


double elapsed_time(struct timespec start, struct timespec end)
{
	return (end.tv_sec - start.tv_sec) 
			+ (end.tv_nsec - start.tv_nsec) * 0.000000001;
}

void printGraph(struct Graph graph)
{
	int n = graph.W_order > graph.F_order ? graph.W_order : graph.F_order;
	
	printf("\nTransitive Matrix  \t\tShortest Pair Path Matrix\n");
	for (int i = 0; i < n; i ++)
	{
		for(int j = 0; j < graph.W_order; j++)
			if (i < graph.W_order)
				printf("%2d | ", graph.W[i][j]);
			else
				printf("  ");

		printf("\t\t");
		
		for(int j = 0; j < graph.F_order; j++)
			if(i < graph.F_order)
				printf("%2d | ", graph.F[i][j]);
			else
				printf("%2s", " ");
		
		printf("\n");
	}
	//EXECUTION TIME FOR WARSHALLS ALGORITHM
	printf("\n%lf time elapsed for WARLSHALLS ALGORITHM\n", graph.W_time);
		
	//EXECUTION TIME FOR FLOYDS ALGORITHM
	printf("%lf time elapsed for FLOYDS ALGORITHM\n", graph.F_time);

}

void transitive_closure_warshalls(int **g, int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = COMPUTE(g[i][j], g[i][k], g[k][j]);
}

void all_pairs_shortest_path_distances_floyds(int **g, int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
}

int **create_graph(int n)
{
	int **graph = (int**) malloc(sizeof(int*) * n);
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		graph[i] = (int*) malloc(sizeof(int) * n);
		for (j = 0; j < n; j++)
			graph[i][j] = 0;
	}

	printf("Enter Matrix row by row: \n");
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			graph[i][j] = VALUE(temp);
		}
	return graph;
}

int main()
{
	struct timespec start, end;
	
	printf("For Warshall's Transitive CLosure\n");
	printf("Enter Order of Matrix: "); scanf("%d", &graph.W_order);

	// INITIALIZE THE GRAPH
	graph.W = create_graph(graph.W_order);

	clock_gettime(CLOCK_REALTIME, &start);
	transitive_closure_warshalls(graph.W, graph.W_order);	
	clock_gettime(CLOCK_REALTIME, &end);
	graph.W_time = elapsed_time(start, end);



	printf("For Floyds Algorithm: Shortest Path Pair\n");
	printf("Enter Order of Matrix: "); scanf("%d", &graph.F_order);
	printf("(NOTE: Enter -1 for INFINITE): \n");

	// INITIALIZE THE GRAPH
	graph.F = create_graph(graph.F_order);

	clock_gettime(CLOCK_REALTIME, &start);
	all_pairs_shortest_path_distances_floyds(graph.F, graph.F_order);
	clock_gettime(CLOCK_REALTIME, &end);
	graph.F_time = elapsed_time(start, end);


	//PRINT BOTH GRAPHS AND EXECUTION TIME
	printGraph(graph);

	return 0;
}
