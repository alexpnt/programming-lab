/*
Scheduling conferences LPA 2013	
Non-greedy solution

by Alexandre Pinto
*/
#include <stdio.h>
#include <string.h>

#define MAXTIME 1000

int timeline[MAXTIME];
int N;

int max();

int main()
{
	int i,begin,end,j;

	while(scanf("%d",&N)!=EOF){
		memset(timeline,0,MAXTIME);
		for(i=0;i<N;i++){
			scanf("%d %d",&begin,&end);
			for(j=begin;j<end;j++)
				timeline[j]++;
		}

		printf("%d\n",max());
	}

	return 0;
}

int max(){

	int i=0,m=0;

	for(i=0;i<MAXTIME;i++){
		if(timeline[i]>m)
			m=timeline[i];
	}

	return m;
}
