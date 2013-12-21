/*
Scheduling conferences LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int begin;
	int end;
}Event;

int N;
Event events[150000];
int rooms[150000];

int findMin();
int compare (const void *, const void *);

int main()
{
	int i;

	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			scanf("%d %d",&events[i].begin,&events[i].end);
		}		
		printf("%d\n",findMin());
	}


	return 0;
}

int findMin(){

 	int nrooms=0,i,j,allocated=0;

 	qsort(events,N,sizeof(Event),compare);
	
	for(i=0;i<N;i++){
		allocated=0;
		for(j=0;j<nrooms;j++){
			if(events[i].begin>=rooms[j]){
				rooms[j]=events[i].end;
				allocated=1;
				break;
			}
		}
		
		if(allocated==0){
			rooms[nrooms]=events[i].end;
			nrooms++;
		}
	}


	return nrooms;

}

int compare(const void *a, const void *b)			
{												
	Event* e1=(Event*)a;
	Event* e2=(Event*)b;

	if((e1->begin-e2->begin)>0)									
        return 1;
    if((e1->begin-e2->begin)<0)									
        return -1;
    return 0;
}
