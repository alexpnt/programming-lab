/*
Tow Towers LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

int LCS[101][101];
int tower1[101];
int tower2[101];

int n1=-1,n2=-1;

int lcs(int*,int*);

int main(){

	int z,i=1;

	while(n1!=0 && n2!=0){
		scanf("%d %d",&n1,&n2);

		if(n1==0 && n2==0)
			break;
		
		for(z=1;z<=n1;z++){
			scanf("%d",&tower1[z]);
		}		
		for(z=1;z<=n2;z++){
			scanf("%d",&tower2[z]);
		}

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",i,lcs(tower1,tower2));
		i++;
	}

	return 0;
}

int lcs(int* tower1,int* tower2){
	
	int i,j;

	for(i=0;i<=n1;i++)
		LCS[i][0]=0;

	for(j=0;j<=n2;j++)
		LCS[0][j]=0;

	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++){
			if(tower1[i]==tower2[j])
				LCS[i][j]=LCS[i-1][j-1]+1;
			else if(LCS[i-1][j]>LCS[i][j-1])
				LCS[i][j]=LCS[i-1][j];
			else
				LCS[i][j]=LCS[i][j-1];
		}
	
	return LCS[n1][n2];
}

