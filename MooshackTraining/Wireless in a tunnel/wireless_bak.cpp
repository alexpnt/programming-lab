/*
Wireless in a tunnel LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct{
	float begin;
	float end;
}Wireless;

int N;
int MAX;
Wireless points[150000];
queue<Wireless> tunnel;									

int findMin();
int compareqk(const void *, const void *);

int main()
{
	int i,p,min;
	float r;

	while(scanf("%d",&MAX)!=EOF){
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d %f",&p,&r);
			if((p-r/2)<0)
				points[i].begin=0;
			else
				points[i].begin=p-r/2;
			if((p+r/2)>MAX)
				points[i].end=MAX;
			else
				points[i].end=p+r/2;
		}

		qsort(points,N,sizeof(Wireless),compareqk);

		/*for(i=0;i<N;i++)
			printf("(%.2f,%.2f)\n",points[i].begin,points[i].end);
		printf("\n");*/

		tunnel=queue<Wireless>();
		min=findMin();
		if(min==-1)
			printf("I give up!\n");
		else
			printf("%d\n",min);
	}		

	return 0;
}

int findMin(){

	int i;
	Wireless last;

	if(points[0].begin==0)	
		tunnel.push(points[0]);
	else
		return -1;

 	for(i=1;i<N;i++){
 		last=tunnel.back();
 		if(points[i].begin==last.begin && points[i].end>last.end){
 				tunnel.pop();
 				tunnel.push(points[i]);
 		}
 		else if(points[i].begin>last.begin && points[i].end>last.end && points[i].begin<=last.end){
 			tunnel.push(points[i]);
 		}

 		last=tunnel.back();
 		if(last.end>=MAX)
 			return tunnel.size();
 	}

 	if(last.end>=MAX)
 			return tunnel.size();
 	else
 		return -1;
}

int compareqk(const void *a, const void *b)			
{												
	Wireless* p1=(Wireless*)a;
	Wireless* p2=(Wireless*)b;

	if((p1->begin-p2->begin)>0)									
        return 1;
    if((p1->begin-p2->begin)<0)									
        return -1;
    return 0;
}
