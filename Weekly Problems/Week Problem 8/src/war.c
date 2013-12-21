/*
War games LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 1000
#define min(a,b) a<b?a:b

typedef struct{
	int u;
	int v;
}Edge;

int dfs[NODES];			/*indice dfs dos nos*/
int low[NODES];			/*valor low dos nos*/
int time;				/*contador*/

int edges[NODES][NODES];	/*grafo*/
int degrees[NODES];
int nVertices;
int nEdges;

Edge stack[(NODES*NODES)/2];		/*pseudo-stack para ir guardando as arestas*/
int sp;								/*stackp pointer*/

void bridge(int,int);
int compareqk(const void *, const void *);


int main(void)
{
	int i,j,z;

	while(scanf("%d %d",&nVertices,&nEdges)!=EOF){
		/*init graph*/
		memset(dfs,0,NODES*sizeof(int));
		memset(degrees,0,nVertices*sizeof(int));

		time=1;
		sp=0;

		for(z=0;z<nEdges;z++){
			scanf("%d %d",&i,&j);
			edges[i][degrees[i]++]=j;			/*i-j*/
			edges[j][degrees[j]++]=i;			/*j-i*/
		}

		for(i=0;i<nVertices;i++)
            if(dfs[i]==0)				
                bridge(i,-1);
		if(sp==0)printf("No road\n");								/*nao ha arestas do tipo bridge*/
		else{
			qsort(stack,sp,sizeof(Edge),compareqk);					/*ordena arestas*/
			for(i=0;i<sp;i++)
				printf("%d %d\n",stack[i].u,stack[i].v);			/*imprime arestas*/
		}
	}
	
	return 0;
}

void bridge(int v, int father){ 
	int i,neighbour;

	low[v] = dfs[v] = time = time+1;			
    
    for(i=0;i<degrees[v];i++){
    	neighbour=edges[v][i];
      	if(dfs[neighbour]==0){					/*se o no ainda n foi visitado*/
          bridge(neighbour,v);
          low[v]= min(low[v],low[neighbour]);	/*atualiza low*/
          if(low[neighbour]>dfs[v]){			/*e' uma aresta do tipo bridge(se for removida aumenta o numero de componentes conexas)*/
          		if(v>neighbour){				/*guarda na pilha de arestas*/
          			stack[sp].u=neighbour;	
          			stack[sp++].v=v;	
          		}
          		else{
          			stack[sp].u=v;
          			stack[sp++].v=neighbour;
          		}
          }
       }else if(neighbour!=father){				/*apenas atualiza o low se o vizinho nao for o proprio no pai ja visitado*/	
          low[v]= min(low[v],low[neighbour]);
       }
    } 
}

int compareqk(const void *a, const void *b)			/*comparador do quicksort*/
{													
	Edge* v1=(Edge*)a;
	Edge* v2=(Edge*)b;

	if(v1->u==v2->u)									
	 	return v1->v-v2->v;
	return v1->u-v2->u;
}
