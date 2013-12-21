/*
Going Erasmus LPA 2013	

by Alexndre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int sat;
	int ects;
}Course;

int N;
int ECTS;
Course uc[300][16];
int K[2][30001];

int knapsack();

int main()
{
	int i,j,ncourses;

	while(scanf("%d %d",&N,&ECTS)!=EOF){
		for(i=0;i<N;i++){

			scanf("%d",&ncourses);
			uc[i][15].ects=ncourses;
			for(j=0;j<ncourses;j++){
				scanf("%d %d",&uc[i][j].ects,&uc[i][j].sat);
			}
		}
		printf("%d\n",knapsack());
	}
	return 0;
}

int knapsack(){
 	
 	int j,i=1,z,m,candidate=0;

	while(i<=N){
		for(j=1;j<=ECTS;j++)
		{
			/*verifica de entre a solucao anterior e das varias disponiveis agora, qual a que maximiza a satisfacao*/
			m=0;
			for(z=0;z<uc[i-1][15].ects;z++){
				if(uc[i-1][z].ects<=j){	
					candidate=K[0][j-uc[i-1][z].ects]+uc[i-1][z].sat;		/*candidato possivel*/
					if(candidate>m)
						m=candidate;		/*atualiza maximo encontrado*/
				}
			}

			if(m>K[0][j])				/*verifica se o maximo encontrado e melhor que a solucao anterior*/
				K[1][j]=m;
		}
		memcpy(K[0],K[1],ECTS*sizeof(int)+1);	/*swap*/
		i++;
	}
		
	return K[1][ECTS];
}
