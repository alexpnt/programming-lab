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

int color=0;
int bi;

void dfs(int,int);
void print_graph();
int getchar_unlocked(void);

int main(){

	char input[10];
	int ptr=0,ch;

	int i,j;
	int z;

	while(1){

		while(1){ch= getchar_unlocked();
		    if (ch==' ' || ch=='\n' || ch==EOF)break;
		    input[ptr++]=(char)ch;
		}if(ch==EOF)break;

		nVertices=atof(input);
		ptr=0;
		memset(input,'\0',10);
		while(1){ch= getchar_unlocked();
		    if (ch==' ' || ch=='\n' || ch==EOF)break;
		    input[ptr++]=(char)ch;
		}
		nEdges=atof(input);
		ptr=0;
		memset(input,'\0',10);

		/*init graph*/
		memset(colors,0,nVertices*sizeof(int));
		memset(visited,0,nVertices*sizeof(int));
		memset(degrees,0,nVertices*sizeof(int));

		/*read graph*/
		for(z=0;z<nEdges;z++){
			while(1){ch= getchar_unlocked();
			    if (ch==' ' || ch=='\n' || ch==EOF)break;
			    input[ptr++]=(char)ch;
			}
			i=atof(input);
			ptr=0;
			memset(input,'\0',10);
			while(1){ch= getchar_unlocked();
			    if (ch==' ' || ch=='\n' || ch==EOF)break;
			    input[ptr++]=(char)ch;
			}
			j=atof(input);
			ptr=0;
			memset(input,'\0',10);

			edges[i-1][degrees[i-1]]=j-1;			/*i-j*/
			edges[j-1][degrees[j-1]]=i-1;			/*j-i*/
			degrees[i-1]++;
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

void print_graph()
{
	int i,j;

	for (i=1; i<=nVertices; i++){
		printf("degree: %d node: %d: ",degrees[i],i);
		for (j=0; j<degrees[i]; j++)
			printf(" %d",edges[i][j]);
			printf("\n");
	}
}





