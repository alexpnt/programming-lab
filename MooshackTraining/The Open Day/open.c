/*
The Open Day LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <string.h>

int N,M;

int adjacency[435][435];
int scheduling[30][30];

int findmax();

int main()
{
	int i,z,k;
	
	while(scanf("%d %d",&N,&M)!=EOF){
		memset(scheduling,-1,sizeof(scheduling));
		for(i=0;i<M;i++){
			scanf("%d %d",&z,&k);
			adjacency[z][k]=1;
			adjacency[k][z]=1;
		}
	}

	printf("%d\n",findmax());
	return 0;
}

int findmax(){
	int max=0,count,i,j,z;

	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			for(z=0;z<=i;z++){
				if(scheduling[j][z]>=0){
					if(adjacency[scheduling[j][z]][i]==1){
						z=i+1;
					}
				}
				else{
					scheduling[j][z]=i;
					j=i+1;
					z=i+1;
				}
			}
		}
	}

	for(i=0;i<N;i++){
		count=0;
		for(j=0;scheduling[i][j]!=-1;j++){
			count++;
		}
		if(count>max)
			max=count;
	}

	return max;

}
