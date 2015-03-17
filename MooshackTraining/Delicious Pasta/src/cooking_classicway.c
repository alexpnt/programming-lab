/*
Delicious Pasta LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int taste;
	int cookingTime;
}Pasta;

int N;
int COOKINGTIME;
Pasta types[300][15];
int K[1000][30001];

int knapsack();

int main()
{
	int i,j,t;

	while(scanf("%d %d",&N,&COOKINGTIME)!=EOF){

		for(i=0;i<N;i++){
			for(j=0;j<COOKINGTIME;j++){
				scanf("%d",&t);
				scanf("%d %d",&types[i][j].cookingTime,&types[i][j].taste);
			}
		}

		printf("%d\n",knapsack());
	}
	
	return 0;
}

int knapsack(){
 	
 	int j,i,z,m,candidate;

	for(i=1;i<=N;i++)
		for(j=1;j<=COOKINGTIME;j++)
		{
			m=0;
			for(z=0;z<COOKINGTIME;z++){
				if(types[i-1][z].cookingTime<=j){	
					candidate=K[i-1][j-types[i-1][z].cookingTime]+types[i-1][z].taste;		/*candidato possivel*/
					if(candidate>m)
						m=candidate;		/*atualiza maximo encontrado*/
				}
			}

			if(m>K[i-1][j])				/*verifica se o maximo encontrado e melhor que a solucao anterior*/
				K[i][j]=m;
			else
				K[i][j]=K[i-1][j];
		}
		
	return K[N][COOKINGTIME];
}
