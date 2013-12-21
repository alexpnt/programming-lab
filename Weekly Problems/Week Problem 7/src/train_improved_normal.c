/*
A mess with the train timetable LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 500

typedef struct{
	int edges[NODES][NODES];
	int degrees[NODES];
	int nVertices;
	int nEdges;
}Graph;

int visited[NODES];
int colors[NODES];

int color=0;
int bi;

void dfs(Graph*,int,int);
void print_graph(Graph *g);

int main(){

	int i,j;
	int z;
	Graph *g;
	
	g=(Graph*)malloc(sizeof(Graph));
	while(scanf("%d %d",&g->nVertices,&g->nEdges)!=EOF){

		/*init graph*/
		memset(colors,0,g->nVertices*sizeof(int));
		memset(visited,0,g->nVertices*sizeof(int));
		memset(g->degrees,0,g->nVertices*sizeof(int));

		/*read graph*/
		for(z=0;z<g->nEdges;z++){
			scanf("%d %d",&i,&j);
			g->edges[i-1][g->degrees[i-1]]=j-1;		/*i-j*/
			g->degrees[i-1]++;

			g->edges[j-1][g->degrees[j-1]]=i-1;		/*j-i*/
			g->degrees[j-1]++;
		}

		bi=1;										/*is bipartite*/
		for(i=0;i<g->nVertices && bi;i++){			/*dfs search*/
			if(visited[i]==0)
				dfs(g,i,0);
		}
		if(bi)
			printf("NOT SURE\n");
		else
			printf("NO\n");			
	}

	free(g);
	return 0;
}

void dfs(Graph *g,int node, int color){

	int i;

	visited[node]=1;
	colors[node]=1-color;

	if(bi){														
		for(i=0;i<g->degrees[node];i++){
				if(visited[g->edges[node][i]]==0)
					dfs(g,g->edges[node][i],1-color);
				else if(colors[node]==colors[g->edges[node][i]]){	/*is not a bipartite graph*/
					bi=0;								
					return;
				}
		}
	}
}

void print_graph(Graph *g)
{
	int i,j;

	for (i=1; i<=g->nVertices; i++){
		printf("degree: %d node: %d: ",g->degrees[i],i);
		for (j=0; j<g->degrees[i]; j++)
			printf(" %d",g->edges[i][j]);
			printf("\n");
	}
}





