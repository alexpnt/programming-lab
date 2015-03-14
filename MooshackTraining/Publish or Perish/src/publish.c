/*
Publish or Perish LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int npapers;
	int funding;
}Project;

int N;
int BUDGET;
int nproposals[200];

Project rUnit [200][10];
int K[2][5001];

int knapsack();

int main()
{
	int i,z;

	scanf("%d %d",&N,&BUDGET);
	for(i=0;i<N;i++){
		scanf("%d",&nproposals[i]);
	}

	for(z=0;z<N;z++){
		for(i=0;i<nproposals[z];i++)
			scanf("%d %d",&rUnit[z][i].funding,&rUnit[z][i].npapers);
	}

	printf("%d\n",knapsack());

	return 0;
}

int knapsack(){
 	
 	int j,i=1,z,m,candidate=0;

	while(i<=N){
		for(j=1;j<=BUDGET;j++)
		{
			/*verifica de entre a solucao anterior e das varias disponiveis agora, qual a que maximiza a satisfacao*/
			m=0;
			for(z=0;z<nproposals[i-1];z++){
				if(rUnit[i-1][z].funding<=j){	
					candidate=K[0][j-rUnit[i-1][z].funding]+rUnit[i-1][z].npapers;		/*candidato possivel*/
					if(candidate>m)
						m=candidate;		/*atualiza maximo encontrado*/
				}
			}

			if(m>K[0][j])				/*verifica se o maximo encontrado e melhor que a solucao anterior*/
				K[1][j]=m;
		}
		memcpy(K[0],K[1],BUDGET*sizeof(int)+1);	/*swap*/
		i++;
	}
		
	return K[1][BUDGET];
}
