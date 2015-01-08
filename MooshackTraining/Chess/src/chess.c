/*
A new chess game LPA 2013

by Alexandre Pinto
*/


#include <stdio.h>
#include <stdlib.h>

char board[401][401];
int counter;

void explore(int,int,int);
void test(int,int);

int main()
{
	int nlines=0,x0,y0,x_plus,y_plus,n_moves,i;

	scanf("%d",&nlines);

	for(i=0;i<nlines;i++){
		scanf("%d %d %d",&x0,&y0,&n_moves);
		x_plus=x0+200;
		y_plus=y0+200;

		test(x_plus,y_plus);
		explore(x_plus,y_plus,n_moves);
	}

	printf("%d\n",counter);

	return 0;
}


void explore(int x,int y,int n){

	int i=0;

	for(i=0;i<8;i++){
		switch(i){
			case 0:{
				if(n>0){
					test(x-2,y-1);
					explore(x-2,y-1,n-1);
				}
				else
					return;
				break;
			}
			case 1:{
				if(n>0){
					test(x-2,y+1);
					explore(x-2,y+1,n-1);
				}
				else
					return;
				break;
			}
			case 2:{
				if(n>0){
					test(x-1,y-2);
					explore(x-1,y-2,n-1);
				}
				else
					return;
				break;
			}
			case 3:{
				if(n>0){
					test(x-1,y+2);
					explore(x-1,y+2,n-1);
				}
				else
					return;
				break;
			}
			case 4:{
				if(n>0){
					test(x+1,y-2);
					explore(x+1,y-2,n-1);
				}
				else
					return;
				break;
			}
			case 5:{
				if(n>0){
					test(x+1,y+2);
					explore(x+1,y+2,n-1);
				}	
				else
					return;
				break;
			}
			case 6:{
				if(n>0){
					test(x+2,y-1);
					explore(x+2,y-1,n-1);
				}
				else
					return;
				break;
			}
			case 7:{
				if(n>0){
					test(x+2,y+1);
					explore(x+2,y+1,n-1);
				}
				else
					return;
				break;
			}
			
		}

	}

}

void test(int x,int y){

	if(!board[x][y]){
		board[x][y]='1';	
		counter++;
	}
}
