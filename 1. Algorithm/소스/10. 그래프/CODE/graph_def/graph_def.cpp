// graph_def.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX_VERTICES 4

typedef struct graph 
{  int node;
   graph *link;
} list;
list *adj_list[MAX_VERTICES];


int adj_mat[MAX_VERTICES][MAX_VERTICES]={
	{0,1,0,1},
	{1,0,1,1},
	{0,1,0,1},
	{1,1,1,0} };
int visited[MAX_VERTICES];
int n=4;

void graph_dfs_list(int v)   /* v는 방문할 노드 */
{
   list *w;
   visited[v] = 1;     /* 노드 v를 방문했음을 체크 */
   printf("%d ", v);   /* 방문한 노드 출력 */
   for(w=adj_list[v]; w; w=w->link)
       /* 방문하지 않은 노드에 대한 깊이우선탐색 */
	 if(!visited[w->node])     
		graph_dfs_list(w->node);
}

/* adj_mat는 그래프를 인접행렬로 표현한 2차 배열 */
void graph_dfs_mat(int v)
{
   int w;
   visited[v] = 1;
   printf("%d ", v);
   for(w=0; w<n; w++) 
       /* 연결된 노드 중 방문된 적이 없는 노드 */
	 if( adj_mat[v][w] && !visited[w] )
	   	graph_dfs_mat(w);
}

/*  */
void read_graph(char *file_name)
{
	int i,j;
	FILE *fp = fopen(file_name, "r");
	if( fp == NULL ) return;
	fscanf(fp, "%d\n", &n);
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		fscanf(fp, "%d", &adj_mat[i][j]);
	}
	}
	fclose(fp);
}

/*  */
void write_graph(char *file_name)
{
	int i,j;
	FILE *fp = fopen(file_name, "w");
	if( fp == NULL ) return;
	fprintf(fp, "%d\n", n);
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		fprintf(fp, " %d ", adj_mat[i][j]);
	}
	fprintf(fp, "\n");
	}
	fclose(fp);
}

void main()
{
	//write_graph("test.gra");
	//read_graph("test.gra");
	graph_dfs_mat(0);
}

