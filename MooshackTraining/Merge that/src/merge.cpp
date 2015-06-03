/*
Merge that! LPA 2013	

by Alexandre Pinto
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct compare  						//comparador para alterar a prioridade da fila de prioridade
{  										//no topo passa a estar sempre o minimo
  bool operator()(const int& left, const int& right)  
  {  
      return left > right;  
  }  
};

int N;
priority_queue<int,vector<int>, compare > files;	//fila de prioridades, mantem o minimo valor no topo

int findMin();

int main()
{
	int i,file;

	while(scanf("%d",&N)!=EOF){
		files=priority_queue<int,vector<int>, compare >();
		for(i=0;i<N;i++){
			scanf("%d",&file);
			files.push(file);
		}		
		printf("%d\n",findMin());
	}

	return 0;
}

int findMin(){

 	int i,minSum=0,res;

 	if(files.size()>1)
 		for(i=0;i<N-1;i++){
	 		res=files.top();
	 		files.pop();
	 		res+=files.top();
	 		files.pop();

	 		minSum+=res;
	 		files.push(res);
 	}
 	else
 		minSum=files.top();

 	return minSum;
}
