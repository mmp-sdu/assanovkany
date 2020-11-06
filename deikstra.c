// learn how to declare a two-dimensional structure

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
// int func(int arg1);


void print_matrix(int** adj_matrix, int size)
{
	int k, j;
	for (k=0; k<size; k++){
		for (j=0; j<size; j++)
		{
			printf("%d ",adj_matrix[k][j]);
		}
		printf("\n");
	}
	
} 
void init_graph(int ** adj_matrix, int size)
{
	adj_matrix[0][0]=0;
	adj_matrix[0][1]=4;
	adj_matrix[0][2]=0;
	adj_matrix[0][3]=0;
	adj_matrix[0][4]=0;
	adj_matrix[1][2]=0;
	adj_matrix[1][3]=7;
	adj_matrix[1][4]=0;
	adj_matrix[2][3]=0;
	adj_matrix[2][4]=1;
	adj_matrix[3][4]=11;
	int i, j;
	for (i=0; i<size; i++)
	{	
		for (j=0; j<size; j++)
		{
			if (i==j)
			{
				adj_matrix[i][j]=0;
			}
			else
			{
				adj_matrix[j][i]=adj_matrix[i][j];
			}
		}
	}
}

void give_memory_back_into_heap(int ** adj_matrix, int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		// freeing elements from a[i][0] up until a[i][size-1]
		free(adj_matrix[i]);
	}
	//freezing the rest
	free(adj_matrix);
}

void deikstra(int ** adj_matrix, int source_vertex, int size);

int minDistance(int* dists, bool* visited, int size)
{
	int min = INT_MAX;
	int min_index;
	int k;
	for (k=0; k<size; k++)
	{
		if( visited[k]==false && dists[k] <= min)
			min = dists[k];
			min_index = k;
	}
	return min_index;
}

int main(){
	
	int N;
	N = 5;
	
	int** adjacency_matrix;
	adjacency_matrix = (int**) malloc(sizeof(int*)*N);
	int k;
	for (k=0; k<N; k++)
	{
		adjacency_matrix[k]=(int*)malloc(sizeof(int)*N);
	}
	printf("before the init\n");	
	print_matrix(adjacency_matrix, N);
	init_graph(adjacency_matrix, N);
	printf("after the init \n");
	print_matrix(adjacency_matrix, N);
	
	deikstra(adjacency_matrix, 0, N);
	give_memory_back_into_heap(adjacency_matrix, N);
	
	return 0;

}
void printSolution(int* dists, int size)
{
	printf("Vertex distance from source \n");
	int k;
	for (k=0; k<size; k++)
	{
		printf("%d tt %d\n", k, dists[k]);
	}
	printf("\n");
}
void deikstra(int ** adj_matrix, int source_vertex, int size){
	int* dists;
	dists = (int*) malloc(sizeof(int)*size);
	int k;
	int  j;
	int u;
	for (k=0; k<size; k++)
	{
		dists[k]=INT_MAX;	
	}
	// all the distances from source_vertex to all other vertices
	bool* visited_vertices;
	visited_vertices = (bool*)malloc(sizeof(bool)*size);
	for (k=0; k<size; k++)
	{
		visited_vertices[k]=false;
	}
	printf("I am in deikstra\n");
	
	dists[source_vertex]=0;
	// Find shortest path for all vertices 
	for (int k = 0; k<size; k++)
	{
		// pick the minimum distance vertex available
		u  = minDistance(dists, visited_vertices, size);
		//mark the picked vertex as visited
		visited_vertices[u]=true;
		// we are updating the distances
		for (j=0; j<size; j++)
		{
			//relaxation technique
			if (visited_vertices[j]==false && adj_matrix[k][j]!= 0 && dists[k]!= INT_MAX && (dists[k]+adj_matrix[k][j]<dists[j]))
			{
				dists[j]=dists[k]+adj_matrix[k][j];
			}
		}
	}
	printSolution(dists, size);
}
