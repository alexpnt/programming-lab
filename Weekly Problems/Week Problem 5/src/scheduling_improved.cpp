/*
Scheduling conferences LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct{
	int begin;
	int end;
}Event;

struct compare  						//comparador para alterar a prioridade da fila de prioridade
{  										//no topo passa a estar sempre o minimo
  bool operator()(const int& left, const int& right)  
  {  
      return left > right;  
  }  
};

int N;
Event events[150000];
priority_queue<int,vector<int>, compare > rooms;	//fila de prioridades, mantem o minimo valor no topo
													//representa as salas a ser usadas
													//cada posicao contem o valor do tempo de fim maximo de todos os eventos a usarem essa sala
int findMin();
int compareqk(const void *, const void *);			//comparador para o quicksort

int main()
{
	int i;

	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			scanf("%d %d",&events[i].begin,&events[i].end);	//guarda eventos
		}		
		printf("%d\n",findMin());
	}


	return 0;
}

int findMin(){

 	int i=0,minLastTime=0;

 	qsort(events,N,sizeof(Event),compareqk);		//ordena os eventos por ordem de inicio
 	rooms.push(events[0].end);						//aloca uma nova sala, colocando la o valor de fim

	for(i=1;i<N;i++){								//para cada evento
		minLastTime=rooms.top();					//vai buscar o minimo valor de fim existente

		if(events[i].begin>=minLastTime){			//se o inicio for maior ou igual, tambem pode usar essa sala
			rooms.pop();							//retira do topo para atualizar
			rooms.push(events[i].end);				//atualiza a sala, com um novo valor de fim (pode levar a reordenamento)
		}
		else{
			rooms.push(events[i].end);				//nao ha uma sala disponivel, logo e' preciso de alocar uma nova sala
		}
	}
	return rooms.size();							// o tamanho da fila de salas, vai ser o numero minimo de salas procurado
}

int compareqk(const void *a, const void *b)			
{												
	Event* e1=(Event*)a;
	Event* e2=(Event*)b;

	if((e1->begin-e2->begin)>0)									
        return 1;
    if((e1->begin-e2->begin)<0)									
        return -1;
    return 0;
}
