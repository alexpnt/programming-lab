/*
Word stretcher LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

#define N 1000

char NW[N][N];
char word1[N];
char word2[N];

int n1,n2;
int alfa=1,beta=1,yotta=1;

int nw(char*,char*);
int max(int,int,int);

int main(){

	int i,j;
	while(scanf("%d %s",&n2,word2)!=EOF)
	{
		scanf("%d %s",&n1,word1);
	
		printf("%d\n",nw(word1,word2));

	}
	return 0;
}

int nw(char* word1,char* word2){
	
	int i,j;

	for(i=0;i<=n1;i++)
		NW[i][0]=-i*beta;

	for(j=0;j<=n2;j++)
		NW[0][j]=-j*beta;

	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++){
			if(word1[i-1]==word2[j-1])
				NW[i][j]=max(NW[i-1][j]-beta,NW[i][j-1]-beta,NW[i-1][j-1]+alfa);
			else
				NW[i][j]=max(NW[i-1][j]-beta,NW[i][j-1]-beta,NW[i-1][j-1]-yotta);
		}
	
	return NW[n1][n2];
}

int max(int a,int b,int c){

	int m=a;

	if(b>m)
		m=b;

	if(c>m)
		m=c;
	return m;
}


