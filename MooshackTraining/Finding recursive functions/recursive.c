/*
Find recursive functions LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 1000

int C[NODES][NODES];
int visited[NODES];
int recursiveNodes[NODES];
int sp;
int nVertices;

void checkPath();
int compareqk(const void *, const void *);
int binary_search(int[],int,int,int);
void print();


int main(){

	int i,j,m,w;

	while(scanf("%d",&nVertices)!=EOF){			/*constroi matriz de adjacencia*/
		for(i=0;i<nVertices;i++){
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d",&w);
				C[i][w]=1;
			}
		}
		memset(recursiveNodes,-1,nVertices*sizeof(int));

		checkPath();
		for(i=0;i<nVertices;i++)
			if(C[i][i])
				printf("%d\n",i);
	}

	return 0;
}


void checkPath(){

	int i,j,k;

	for(k=0;k<nVertices;k++)
		for(i=0;i<nVertices;i++)
			for(j=0;j<nVertices;j++){
				if(C[i][k] && C[k][j])
					C[i][j]=1;
			}
}

int compareqk(const void * a, const void * b)
{
  return (*(int*)a-*(int*)b);
}

void print(){

	int i,j;

	for(i=0;i<nVertices;i++){
		for(j=0;j<nVertices;j++)
			printf("%d ",C[i][j]);
		printf("\n");
	}
	printf("\n");
}






