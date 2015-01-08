/*
All squares LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

void count_squares(int,int,int);

int counter=0,x,y;

int main()
{
	int k;

	while(1){
		scanf("%d %d %d",&k,&x,&y);
		if(k==0 && x==0 && y==0)
			break;
		count_squares(k,1024,1024);
		printf("%3d\n",counter);
		counter=0;
	}
 
	return 0;
}

void count_squares(int k,int x0,int y0){

	int len=2*k+1;


	if(k<=1){
		if(x>=(x0-len/2) && x<=(x0+len/2) && y<=(y0+len/2) && y>=(y0-len/2))
			counter++;
		return;
	}
	else{

		if(x>=(x0-len/2) && x<=(x0+len/2) && y<=(y0+len/2) && y>=(y0-len/2))
			counter++;

		if(x<x0 && y>y0)
			count_squares(k/2,x0-len/2,y0+len/2);
		else if(x>x0 && y>y0)
			count_squares(k/2,x0+len/2,y0+len/2);
		else if(x<x0 && y<y0)
			count_squares(k/2,x0-len/2,y0-len/2);
		else if(x>x0 && y<y0)
			count_squares(k/2,x0+len/2,y0-len/2);
	}
}

