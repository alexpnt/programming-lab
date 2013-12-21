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
int npastas[1000];

Pasta types[300][15];
int K[2][30001];

int knapsack();

int main()
{
	int i,j,t;

	while(scanf("%d %d",&N,&COOKINGTIME)!=EOF){

		for(i=0;i<N;i++){
			for(j=0;j<COOKINGTIME;j++){
				scanf("%d",&t);
				npastas[t-1]++;
				scanf("%d %d",&types[i][j].cookingTime,&types[i][j].taste);
			}
		}

		printf("%d\n",knapsack());
	}
	
	return 0;
}

int knapsack(){
 	
 	int j,i=1,z,m,candidate=0;

	while(i<=N){
		for(j=1;j<=COOKINGTIME;j++)
		{
			/*verifica de entre a solucao anterior e das varias disponiveis agora, qual a que maximiza a satisfacao*/
			m=0;
			for(z=0;z<npastas[i-1];z++){
				if(types[i-1][z].cookingTime<=j){	
					candidate=K[0][j-types[i-1][z].cookingTime]+types[i-1][z].taste;		/*candidato possivel*/
					if(candidate>m)
						m=candidate;		/*atualiza maximo encontrado*/
				}
			}

			if(m>K[0][j])				/*verifica se o maximo encontrado e melhor que a solucao anterior*/
				K[1][j]=m;
		}
		memcpy(K[0],K[1],COOKINGTIME*sizeof(int)+1);	/*swap*/
		i++;
	}
		
	return K[1][COOKINGTIME];
}

