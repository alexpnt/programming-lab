/*
Telephone LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOS 1000

#define min(a,b) a<b?a:b

int low[NOS];
int dfs[NOS];
int time;
int grafo[NOS][NOS];
int n_viz[NOS];
int marked[NOS];
int n,m;
int critical;

void art(int v) {

	int i,w;

	low[v] = dfs[v] = time = time+1;

	for(i=0; i<n_viz[v]; i++) {
		w = grafo[v][i];
		if(dfs[w] == 0) {
			art(w);
			low[v] = min(low[v], low[w]);
			
			if(dfs[v]==1 && dfs[w]!=2) {
				if(marked[v]==0){
					marked[v]=1;
					critical++;
				}
			}
			if(dfs[v]!=1 && low[w]>=dfs[v]) {
				if(marked[v]==0){
					marked[v]=1;
					critical++;
				}
			}
		}
		else {
			low[v] = min(low[v], dfs[w]);
		}
	}
}


int main(void)
{
	int i;
	int t;
	int number,firstnumber;
	char ch;

	while(scanf("%d",&t)!=EOF){
		if(t==0){
			break;
		}
		memset(n_viz, 0, 4*NOS);
		memset(dfs, 0, 4*NOS);
		time=0;

		while(1){
			scanf("%d%c",&number,&ch);
			if(number==0 && ch=='\n'){
				break;
			}
			else{
				firstnumber=number;
				while(1){
					scanf("%d%c",&number,&ch);
					grafo[firstnumber-1][n_viz[firstnumber-1]++]=number-1;
					grafo[number-1][n_viz[number-1]++]=firstnumber-1;
					if(ch=='\n'){
						break;
					}
				}
			}
		}
/*
		for(i=0;i<NOS;i++){
			printf("%d: ",i);
			for(j=0;j<n_viz[i];j++)
				printf("%d ",grafo[i][j]);
			printf("\n");
		}
*/
		for(i=0;i<NOS;i++){
			art(i);
			memset(dfs, 0, 4*NOS);
			memset(low, 0, 4*NOS);
			time=0;
		}
		printf("%d\n",critical);
		memset(marked, 0, 4*NOS);
		memset(grafo,0,NOS*NOS);
		critical=0;
		/*return 0;*/		
	}
	
	return 0;
}
