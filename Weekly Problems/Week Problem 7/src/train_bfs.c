/*
A mess with the train timetable LPA 2013	

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODES 500
#define EDGES 65000
#define QUEUE_SIZE 500

typedef struct {		
	int q[QUEUE_SIZE];
	int first,last;
	int count;
}queue;

int bfs();
void init_queue(queue *);
void enqueue(queue *,int);
int dequeue(queue *);
int is_empty(queue *);

int adjacency[NODES][NODES];
int colors[NODES];

int n,m;

int main(){

	int i,j,z;
	
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(adjacency,0,sizeof(adjacency));
		memset(colors,0,n*sizeof(int));

		for(z=0;z<m;z++){
			scanf("%d %d",&i,&j);
			adjacency[i-1][j-1]=1;
			adjacency[j-1][i-1]=1;
		}

		if(bfs())
			printf("NOT SURE\n");
		else
			printf("NO\n");
	}
	return 0;
}


int bfs(){

	int i,j,next;
	queue q;

	for(i=0;i<n;i++){
		if(colors[i]==0){
			init_queue(&q);
			colors[i]=1;
			enqueue(&q,i);
			while(is_empty(&q)==0){
				next=dequeue(&q);
				for(j=0;j<n;j++){
					if(adjacency[j][next] && next!=j){
						if(colors[j]==0){
							if(colors[next]==1)
								colors[j]=2;
							else
								colors[j]=1;
							enqueue(&q,j);
						}
						else if(colors[next]==colors[j])
							return 0;
					}
				}
			}
		}
	}
	return 1;
}

void init_queue(queue *q)
{
	q->first = 0;
	q->last = QUEUE_SIZE - 1;
	q->count = 0;
}
void enqueue(queue *q,int x)
{
	q->last = (q->last + 1) % QUEUE_SIZE;
	q->q[ q->last ] = x;
	q->count = q->count + 1;
}
int dequeue(queue *q)
{
	int x = q->q[ q->first ];
	q->first = (q->first + 1) % QUEUE_SIZE;
	q->count = q->count - 1;
	return x;
}

int is_empty(queue *q){
	if(q->count==0)
		return 1;
	else
		return 0;
}
