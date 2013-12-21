/*
Printing in a peer-2-peer network LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

int adjacency[35][35];
int printers[35];

int counter=0;
int best=36;
int n;

void find_min(int);
int check();

int main(){

	int i,j;

	scanf("%d",&n);
	while(scanf("%d %d",&i,&j)!=EOF){		/*constroi matriz de adjacencia*/
		adjacency[i-1][j-1]=1;						
		adjacency[j-1][i-1]=1;
	}

	for(i=0;i<n;i++){					/*procura configuracao partindo dos nos de nivel 1*/
		find_min(i);
		counter--;
	}
	printf("%d\n",best);

	return 0;
}

/*gera combinacoes e testa cada uma*/
void find_min(int j){

	int i;

	printers[j]=1;					/*no com impressora*/			
	counter++;						/*incrementa impressoras*/

	/*se o numero de impressoras for maior do que o minimo maximo necessario ou for pior ou igual ao melhor*/
	if(counter>=best || counter>(n/3+1))
		return;

	if(check()){	
		if(counter<best)			
			best=counter;			/*atualiza melhor solucao*/
		return;						/*nao pesquisa niveis abaixo*/
	}

	if(j==(n-1)){					/*caso terminal da arvore de combinacoes*/
		return;
	}
	else{
		for(i=j+1;i<n;i++){			/*depth-first search*/
			find_min(i);	
			printers[i]=0;			/*desfaz alteracoes*/
			counter--;				/*sobe na arvore*/
		}
	}

	printers[j]=0;					/*desfaz alteracoes*/


}

int check(){

	int i,j,count=0;

	for(i=0;i<n;i++){
		if(printers[i]==1){		/* no contem uma impressora*/
			count++;
			continue;
		}			
		for(j=0;j<n;j++){
			if(adjacency[i][j]==1 && printers[j]==1){		/*um vizinho do no contem uma impressora*/
				count++;
				break;
			}
		}

		if(j==n)		/*existe um no que nao consegue alcancar impressoras*/
			return 0;
	}

	if(count==n)
		return 1;
	else
		return 0;
}


