/*
Friends and pizza LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int value;
	int choices[4];
}Friend;									/*Amigo - Valor mais escolhas*/

Friend friends[2000];						/*amigos e seus valores+escolhas*/
int menu[200];								/*menu da pizza, 1 - ingrediente posto, 0 - nao */
int fixed[200];								/*ingredientes em que se consegue ser a certeza que vao aparecer no menu final*/
int unit_sat_unsat[200][2];					/*insatisfacao proveniente das clausulas unitarias, para cada ingrediente, colocado ou nao, 0 - colocando, 1 - nao colocando*/
int accumulated_unitary_bounds[200];		/*bounds minimos acumulados, desde cada no da arvore de pesquisa ate ao fim*/
int n,m;
int upper_bound=200000;						/*upper-bound ou best, representa a solucao final*/

void dpll_search(int,int);	
int parcial_unhappinesss(int);
int binary_ternary_bound(int,int);

void prefix();
int up1(int);
int up3(int);
void walk_sat(int);	

void printMenu();
void printFriends();
void printUnitSums();

int main()
{
	int i,j,m_;

	/*memset(fixed,-1,sizeof(fixed));				-1, ingrediente nao fixo*/
	scanf("%d %d",&n,&m_);
	m=m_;
	for(i=0;i<m;i++){

		scanf("%d",&(friends[i].value));
		j=0;
		do{
			scanf("%d",&(friends[i].choices[j]));
		}while(friends[i].choices[j++]!=0);
		friends[i].choices[3]=j-1;						/*numero de ingredientes*/

		if(friends[i].choices[3]==1 && friends[i].choices[0]>0){
			unit_sat_unsat[friends[i].choices[0]-1][0]+=friends[i].value;	/*soma a insatisfacao desta clausula unitaria = insatisfacao se colocar este ingrediente*/
		}
		else if(friends[i].choices[3]==1 && friends[i].choices[0]<0){		/*soma a insatisfacao desta clausula unitaria = insatisfacao se nao colocar este ingrediente*/
			unit_sat_unsat[-(friends[i].choices[0])-1][1]+=friends[i].value;
		}
	}
	m=m_;

	accumulated_unitary_bounds[n-1]=unit_sat_unsat[n-1][0];				/*cria vetor de bounds acumulados, soma sempre o minimo de insatisfacao possivel para esse ingrediente*/	
	if(unit_sat_unsat[n-1][1]<accumulated_unitary_bounds[n-1])			/*cada posicao vai corresponder ao bound minimo nesse nó*/
		accumulated_unitary_bounds[n-1]=unit_sat_unsat[n-1][1];			/*cada posicao contem a soma de todos os bounds minimos de todos os nos para baixo*/

	for(j=n-2; j>=0; j--) {
		accumulated_unitary_bounds[j]=accumulated_unitary_bounds[j+1]+unit_sat_unsat[j][0];
		if(unit_sat_unsat[j][1]<unit_sat_unsat[j][0]){
			accumulated_unitary_bounds[j]=accumulated_unitary_bounds[j+1]+unit_sat_unsat[j][1];
		}
	}

	/*prefix();
	walk_sat(1);*/
	dpll_search(0,1);
	dpll_search(0,0);

	printf("%d\n",upper_bound);

	return 0;
}

/*Pesquisa pela arvore de possibilidades
Algoritmo de pesquisa: DPLL (Davis–Putnam–Logemann–Loveland ) + Branch and Bound
Permite simular a introdução de ingrediente a ingrediente, de cada vez,
uma vez que cada no, gera dois filhos, 1 e 0,  1 (coloca proximo ingrediente), 0 (nao coloca proximo ingrediente)
*/
void dpll_search(int index,int val){

	int unsat,parcial_unsat;

	menu[index]=val;									/*escolhe/nao escolhe ingrediente*/

	if(index==(n-1)){									/*chegou a uma folha (menu)*/
		unsat=parcial_unhappinesss(index);
		if(unsat<upper_bound)							/*atualiza best se a satisfacao alcancada for melhor*/
			upper_bound=unsat;		
		menu[index]=(val+1)%2;							/*desfaz alteracoes*/
		return;
	}

	parcial_unsat=parcial_unhappinesss(index);			/*satisfacao parcial com todos os ingredientes ja colocados*/
	if(parcial_unsat+unit_sat_unsat[index+1][0]+accumulated_unitary_bounds[index+2]<upper_bound){	/*se parcial + bound > best, n vale a pena continuar*/										/*nao fixou, branch nos 2 ramos*/
			dpll_search(index+1,0);
			dpll_search(index+1,1);	
	}
	if(parcial_unsat+unit_sat_unsat[index+1][1]+accumulated_unitary_bounds[index+2]<upper_bound){	/*se parcial + bound > best, n vale a pena continuar*/										/*nao fixou, branch nos 2 ramos*/
			dpll_search(index+1,0);
			dpll_search(index+1,1);	
	}

	menu[index]=(val+1)%2;								/*desfaz alteracoes*/
}

/*calcula a isnatisfacao parcial para o menu atual, com os ingredientes ja colocados*/
int parcial_unhappinesss(int index){

	register int i,j,n_choices,choice;
	register int unhappiness=0,happy;

	for(i=0;i<m;i++){									/*para cada amigo*/
		n_choices=friends[i].choices[3];
		happy=0;
		
		for(j=0;j<n_choices;j++){						/*para cada escolha*/
			choice=friends[i].choices[j];
			if(choice>(index+1)){						/*escolha de um ingrediente ainda nao decidido, considera hapy*/
				happy=1;
				break;
			}
			else if(choice>0 && menu[choice-1]==1){		/*ingrediente colocado e' satisfeito*/
				happy=1;
				break;
			}
			else if(choice<0 && menu[-choice-1]==0){	/*ingrediente nao colocado e' satisfeito*/
				happy=1;
				break;
			}
		}
		if(happy==0){									/*insatisfeito, soma valor*/
			unhappiness+=friends[i].value;
			if(unhappiness>upper_bound)
				return unhappiness;
		}
	}

	return unhappiness;
}

/*analiza as combinacoes onde o ingrediente futuro aparece tambem insatisfeito*/
int binary_ternary_bound(int index,int val){

	int lower=0,i,j,feasible=0,unit,unhappy;

	for(i=0;i<m;i++){
		if(friends[i].choices[3]>1){		/*clausulas binarias e ternarias*/
			feasible=0;
			unit=0;
			unhappy=0;
			for(j=0;j<friends[i].choices[3];j++){			/*verifica se contem o ingrediente insatisfeito*/
				if(abs(friends[i].choices[j])==(index+1)){
					if((friends[i].choices[j]>0 && val==0) || (friends[i].choices[j]<0 && val==1))
						unit=1;
				}
				else if(abs(friends[i].choices[j])<(index+1)){	/*apena ingredientes ja escolhidos*/
						feasible++;
				}
			}

			if((feasible+1)==friends[i].choices[3] && unit){	/*conta quantos ingredientes insatsfeitos*/
				for(j=0;j<friends[i].choices[3];j++){
					if(abs(friends[i].choices[j])==(index+1))
						continue;
					if(friends[i].choices[j]>0 && menu[friends[i].choices[j]-1]==0)
						unhappy++;
					else if(friends[i].choices[j]<0 && menu[-friends[i].choices[j]-1]==1)
						unhappy++;
					else
						break;
				}
			}

			if(unhappy==friends[i].choices[3])	/* ingredientes todos insatisfeitos, contribui para o bound*/
				lower+=friends[i].value;
		}
	}

	return lower;
}

/*tenta fixar alguns ingredientes*/
void prefix(){

	int up_1,up_3,i;
	for(i=0;i<n;i++){
		up_1=up1(i);
		up_3=up3(i);
		if(up_1==1 || up_3==1)
			fixed[i]=1;
		if(up_1==0 || up_3==0)
			fixed[i]=0;
	}
}


/*Unit Propagation 1: Pure Literal Rule, tambem conhecido por Monotone variable fixing*/
int up1(int index){

	int i,j,ni=0,pi=0;

	for(i=0;i<m;i++){
		for(j=0;j<friends[i].choices[3];j++){
			if(friends[i].choices[j]==(index+1)){
				pi++;
				break;
			}
			else if(friends[i].choices[j]==-(index+1)){
				ni++;
				break;
			}
		}
	}

	if(ni==0)
		return 1;
	else if(pi==0)
		return 0;
	else
		return -1;
}

/*Unit Propagation 3: Dominating unit-clause rule*/
int up3(int index){

	int i,j,ni=0,pi=0;

	for(i=0;i<m;i++){
		for(j=0;j<friends[i].choices[3];j++){
			if(friends[i].choices[j]==(index+1)){
				pi+=friends[i].value;
				break;
			}
			else if(friends[i].choices[j]==-(index+1)){
				ni+=friends[i].value;
				break;
			}
		}
	}

	if(pi==ni)
		return 1;
	else if(unit_sat_unsat[index][0]>=ni)
		return 0;
	else if(unit_sat_unsat[index][1]>=pi)
		return 1;
	else
		return -1;
}

/*Heuristica para calcular um upper bound inicial - Pseudo Walk-Sat*/
void walk_sat(int max_tries){

	int local=accumulated_unitary_bounds[0];
	int i,j;

	/*menu sem ingredientes*/
	local=parcial_unhappinesss(n-1);
	if(local<upper_bound){
		upper_bound=local;
	}

	srand(time(NULL));
	for(i=0;i<max_tries;i++){

		/*configuracao random*/
		for(j=0;j<n;j++){
			menu[j]=rand()%2;
		}

		/*atualiza upper bound*/
		local=parcial_unhappinesss(n-1);
		if(local<upper_bound){
			upper_bound=local;
		}
	}

	memset(menu,0,sizeof(menu));
	return;
}


/*funcoes auxiliares/debug */
void printMenu(){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",menu[i]);
    }
    printf("\n");
}

void printFriends(){
    int i,j;
    for(i=0;i<m;i++){
        printf("%d ",friends[i].value);
        for(j=0;j<4;j++)
        	printf("%d ",friends[i].choices[j]);
        printf("\n");
    }
    printf("\n");
}

void printUnitSums(){

	int i;

	for(i=0;i<n;i++)
		printf("i: %d p: %d n: %d\n",i,unit_sat_unsat[i][0],unit_sat_unsat[i][1]);
}
