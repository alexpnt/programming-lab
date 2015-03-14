/*
(Un)social network LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

#define NODES 100

int adjacency[NODES][NODES];
int neighbor[NODES];

int best=0;
int n,m;

void mis(int,int);

int main(){

	int i,j,z;

	while(scanf("%d %d",&n,&m)!=EOF){		/*constroi matriz de adjacencia*/
		for(z=0;z<m;z++){
			scanf("%d %d",&i,&j);
			adjacency[i][j]=1;						
			adjacency[j][i]=1;
		}

		for(i=0;i<n;i++){
			mis(i,0);
		}

		printf("%d\n",(best+1));	
	}

	return 0;
}

void mis(int v,int size){

	int i,j,s=0;;

	if(size>best)
		best=size;
	
	for(i=v+1;i<n;i++){
		if(adjacency[i][v]==1)
			neighbor[i]++;
	}

	for(i=v+1;i<n;i++){
		s=0;						/*branch and bound*/
		for(j=i;j<n;j++)
			if(neighbor[j]==0)
				s++;

		if((size+s)>best)
			if(neighbor[i]==0)
				mis(i,size+1);
	}

	for(i=v+1;i<n;i++){
		if(adjacency[i][v]==1)
			neighbor[i]--;
	}
}
