// graph_def.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#define MAX_VERTICES 4

struct node
{  
   int vertex;
   struct node *link;
};

struct node *adj_list[MAX_VERTICES]=
{  };

int visited[MAX_VERTICES];

// ��������Ʈ�� ǥ���� �׷����� �ʱ�ȭ
void graph_init()
{

}

// ��������Ʈ�� ǥ���� �׷����� ���̿켱Ž��
void graph_dfs_list(int v)   
{
   list *w;
   visited[v] = 1;     // ��� v�� �湮������ üũ 
   printf("%d ", v);   // �湮�� ��� ��� 
   for(w=adj_list[v]; w; w=w->link)
      if(!visited[w->node])     
		graph_dfs_list(w->node);
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
	graph_dfs_list(0);
}

enum { A, B, C, D, E, F, N };
const char* name = "ABCDEF";

// ��������Ʈ�� ǥ���� �׷����� ������ �߰��Ѵ�.
void add_edge(int v1, int v2)
{
	struct node *n1 = (struct node *)malloc(sizeof(struct node));
	if( n1 == NULL ) return;
	struct node *n2 = (struct node *)malloc(sizeof(struct node));
	if( n2 == NULL ) return;
	for( p=adj_list[v1]; p; p=p->link; )
		;

}
