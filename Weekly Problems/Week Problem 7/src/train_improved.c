/*
A mess with the train timetable LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 500

int edges[NODES][NODES];
int degrees[NODES];
int nVertices;
int nEdges;

int visited[NODES];
int colors[NODES];

int bi;

void dfs(int,int);
int getchar_unlocked(void);
int readLine(int * a, int * b);

int main(){

	int i,j;
	int z;

	while(readLine(&nVertices,&nEdges)!=-1){

		/*init graph*/
		memset(colors,0,nVertices*sizeof(int));
		memset(visited,0,nVertices*sizeof(int));
		memset(degrees,0,nVertices*sizeof(int));

		/*read graph*/
		for(z=0;z<nEdges;z++){
			readLine(&i,&j);
			edges[i-1][degrees[i-1]]=j-1;			/*i-j*/
			degrees[i-1]++;

			edges[j-1][degrees[j-1]]=i-1;			/*j-i*/
			degrees[j-1]++;
		}

		bi=1;											/*is bipartite*/
		for(i=(nVertices-1);i>=0 && bi;i--){			/*dfs search*/
			if(visited[i]==0)
				dfs(i,0);
		}
		if(bi)
			printf("NOT SURE\n");
		else
			printf("NO\n");			
	}

	return 0;
}

void dfs(int node, int color){

	int i;

	visited[node]=1;
	colors[node]=1-color;

	if(bi){														
		for(i=(degrees[node]-1);i>=0;i--){
				if(visited[edges[node][i]]==0)
					dfs(edges[node][i],1-color);
				else if(colors[node]==colors[edges[node][i]]){	/*is not a bipartite graph*/
					bi=0;								
					return;
				}
		}
	}
}

inline int readLine(int * a, int * b)
{
    *a = 0;
    *b = 0;
    int tmp = getchar_unlocked();
    if (tmp == EOF) return -1;
    while (tmp != ' ')
    {
         *a = *a*10 + (tmp-48);
         tmp = getchar_unlocked();
    }
    tmp = getchar_unlocked();
    while (tmp != '\n')
    {
         *b = *b*10 + (tmp-48);
         tmp = getchar_unlocked();
    }
    return 0;
}





