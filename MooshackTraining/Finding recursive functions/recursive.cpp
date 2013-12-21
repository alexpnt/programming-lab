#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 500

int graph[NODES][NODES];
int visited[NODES];
int recursiveNodes[NODES];
int sp;
int n;

int cycle_found;

void cycle(int,int);
int compareqk(const void *, const void *);
int binary_search(int,int,int,int);
void print();

int main(){

	int i,j,m,w;

	while(scanf("%d",&n)!=EOF){			/*constroi matriz de adjacencia*/
		for(i=0;i<n;i++){
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d",&w);
				graph[i][w]=1;
			}
		}

		for(i=0;i<n;i++){
			memset(visited,0,n*sizeof(int));
			cycle(i,-1);
		}

		qsort(recursiveNodes,sp,sizeof(int),compareqk);
		for(i=0;i<sp;i++)
			printf("%d\n",recursiveNodes[i]);
	}

	return 0;
}

void cycle(int node,int parent){

	int v;

	visited[node]=1;
	for(v=0;v<n;v++)
		if(graph[node][v] && v!=parent){
			if(visited[v]==0){
				cycle(v,node);						/*(node,v) is a forward edge*/
			}
			else if(visited[v]==1 && binary_search(recursiveNodes,0,sp,v)!=-1){
				printf("bs: %d\n",binary_search(recursiveNodes,0,sp,v) );
				recursiveNodes[sp++]=v;	/*(node,v) is a back edge*/
				
			}
		}
	visited[node]=2;

}

int binary_search(int a[], int low, int high, int target) {
    while (low <= high) {
        int middle = low + (high - low)/2;
        if (target < a[middle])
            high = middle - 1;
        else if (target > a[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

int compareqk(const void * a, const void * b)
{
  return (*(int*)a-*(int*)b);
}

void print(){

	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",graph[i][j]);
		printf("\n");
	}
	printf("\n");
}




