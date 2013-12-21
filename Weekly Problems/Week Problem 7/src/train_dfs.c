/*
A mess with the train timetable LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 500
#define EDGES 65000

int adjacency[NODES][NODES];
int visited[NODES];

int colors[NODES];
int color=0;

int n,m;

int bi;

void dfs(int,int);

int main(){

	int i,j,z;

	while(scanf("%d %d",&n,&m)!=EOF){
		memset(adjacency,0,sizeof(adjacency));
		memset(colors,0,n*sizeof(int));
		memset(visited,0,n*sizeof(int));	/*white*/

		for(z=0;z<m;z++){
			scanf("%d %d",&i,&j);
			adjacency[i-1][j-1]=1;
			adjacency[j-1][i-1]=1;
		}

		bi=1;
		for(i=0;i<n && bi;i++){
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
		for(i=0;i<n;i++){
			if(adjacency[node][i]){
				if(visited[i]==0)
					dfs(i,1-color);
				else if(colors[node]==colors[i]){
					bi=0;
					return;
				}
			}
		}
	}

}




