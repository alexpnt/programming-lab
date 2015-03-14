/*
The Trip of Mr. Rowan LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int places[20][2];
float dist[20][20];
int visit[20];

float best=RAND_MAX;
int n,counter=0;

void shortPath(int,float);
float calcDist(int,int,int,int);
void calcDistances();

int main()
{
	int i;

	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d %d",&places[i][0],&places[i][1]);

		calcDistances();
		for(i=0;i<n;i++)
			shortPath(i,0);
		printf("%.3f\n",best);
	}

	return 0;
}
void shortPath(int v,float len){

	int i;

	if(len>=best)
		return;

	if(counter==n && len<best)
	{	
		best=len;
		return;
	}

	for(i=0;i<n;i++)
		if(visit[i]==0){
			counter++;
			visit[i]=1;
			shortPath(i,len+dist[v][i]);
			visit[i]=0;
			counter--;
		}
}


float calcDist(int x1,int y1,int x2,int y2){

	return 	sqrt(pow((x1-x2),2)+pow((y1-y2),2));

}

void calcDistances(){

	int i,j;

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			dist[i][j]=calcDist(places[i][0],places[i][1],places[j][0],places[j][1]);
			dist[j][i]=dist[i][j];
		}
}

