/*
How many rooms LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

#define N 500

int map[N][N];
char history[N][N];

int lines,col;
int max;

void visit(int,int);

int main(){

	int i,j;

	while(scanf("%d %d",&lines,&col)!=EOF){
		for(i=0;i<lines;i++)
			for(j=0;j<col;j++)	
				scanf("%d",&map[i][j]);


		for(i=0;i<lines;i++)
			for(j=0;j<col;j++)
				history[i][j]='0';

		max=lines*col;
		for(i=0;i<lines;i++)
			for(j=0;j<col;j++)
				visit(i,j);

		printf("%d\n",max);

	}
	return 0;
}

void visit(int x,int y){

	int val;


	val=map[x][y];
	history[x][y]='1';

	if(x-1>=0 && (val==0 || val==1 || val==4 || val==5 || val==8 || val==9 || val==12 || val==13)){
		if(history[x-1][y]=='0'){
			visit(x-1,y);		
			max--;
		}
	}
	if(y+1<col && (val==0 || val==1 || val==2 || val==3 || val==8 || val==9 || val==10 || val==11)){
		if(history[x][y+1]=='0'){
			visit(x,y+1);		
			max--;
		}
	}
	if(x+1<lines && (val==0 || val==1 || val==2 || val==3 || val==4 || val==5 || val==6 || val==7)){
		if(history[x+1][y]=='0'){
			visit(x+1,y);		
			max--;
		}
	}
	if(y-1>=0 && (val==0 || val==2 || val==4 || val==6 || val==8 || val==10 || val==12 || val==14)){
		if(history[x][y-1]=='0'){
			visit(x,y-1);		
			max--;
		}
	}
}

