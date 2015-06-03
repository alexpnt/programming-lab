/*
Lift Hopping! LPA 2013
by Alexandre Pinto
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <set>

using namespace std;

#define NODES 500

void dijkstra(int,int);

int graph[NODES][NODES];
int nVertices;
int nEdges;
int dist[NODES];


int main(){

	int i,j,z,w;

	while(scanf("%d %d",&nVertices,&nEdges)!=EOF){
		memset(graph,-1,sizeof(graph));
		for(z=0;z<nEdges;z++){
			scanf("%d %d %d",&i,&j,&w);		
			graph[i-1][j-1]=w;
			graph[j-1][i-1]=w;
		}

		/*for(i=0;i<nVertices;i++){
			for(j=0;j<nVertices;j++)
				printf("%d ",graph[i][j]);
			printf("\n");
		}*/
			
		dijkstra(0,nVertices-1);
		printf("Shortest path from source to end is %d\n",dist[nVertices-1]);

		for(i=0;i<nVertices;i++){
			printf("dist[%d]=%d\n",i,dist[i]);
		}
	}
	return 0;
}



struct ltDist{
	bool operator()(int u,int v)const {
		return make_pair(dist[u],u)<make_pair(dist[v],v);
	}
};


//com listas de adjacencia fica (m+n)log(n) !!!! 
void dijkstra(int source,int end){

	for(int i=0;i<nVertices;i++)
		dist[i]=INT_MAX;			//vertices com distancias infinitas

	dist[source]=0;							

	set<int,ltDist> q;				//conjunto de vertices que faltam analisar
	q.insert(source);				

	while(!q.empty()){
		int u=*q.begin();			//retira proximo no com a menor distancia
		q.erase(q.begin());

		if(u==end)
			break;
		for(int v=0;v<nVertices;v++)		
			if(graph[u][v]!=-1){					//percorre todos os vizinhos
				int newDist=dist[u]+graph[u][v];	
				if(newDist<dist[v]){				//atualiza o comprimento
					if(q.count(v))	
						q.erase(v);
					dist[v]=newDist;
					q.insert(v);
				}
			}
	}
}
