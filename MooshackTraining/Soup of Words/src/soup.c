/*
Soup of Words LPA 2013

by Alexandre Pinto
*/
#include <stdio.h>

#define N 30

int order[N];
char soup[N][N];

int diff(char*,char*);

int main()
{
	int n,i;

	while(scanf("%d",&n)!=EOF){
		scanf("%s",soup[0]);

		for(i=1;i<n;i++){
			scanf("%s",soup[i]);
			order[diff(soup[0],soup[i])]=i;
		}

		for(i=0;i<n;i++)
			printf("%s\n",soup[order[i]]);
	}

	return 0;
}

int diff(char* word1,char* word2){


	int i=0,counter=0;

	while(word1[i]){
		if(word1[i]!=word2[i]){
			counter++;
		}
		i++;
	}

	return counter;
}
