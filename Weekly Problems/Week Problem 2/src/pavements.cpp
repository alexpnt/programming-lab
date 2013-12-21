/*
Portuguese Pavements LPA 2013

by Alexandre Pinto
*/
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void design(int);
void rotate(int);
void deny(int,int,int,int);

char pavement[1024][1024];
int r;

int main(){

	int n,i;

	while(scanf("%d %d",&n,&r)!=EOF){
		design(n);

		for(i=0;i<pow(2,n);i++){				//print output
			write(1,pavement[i],(size_t)pow(2,n));
			printf("\n");
		}
	}
}

void design(int n){
	
	int i,j,half_power,power;

	if(n==0){
		pavement[0][0]='0';
	}
	else{
		design(n-1);

		power=(int)pow(2,float(n));
		half_power=power/2;
		
		for(i=0;i<half_power;i++){								//1º quadrant
			memcpy(pavement[i]+half_power,pavement[i],half_power);
		}

		for(i=half_power;i<power;i++){							//3º quadrant
			memcpy(pavement[i],pavement[i-half_power],half_power);
		}

		for(i=half_power;i<power;i++){							//4ºquadrant, negating values
			for(j=half_power;j<power;j++){
				if(pavement[i-half_power][j]=='0')
					pavement[i][j]='1';
				else 
					pavement[i][j]='0';
			}
		}

		rotate(n);
	}
}

void rotate(int n){

	int rem,half_power,power;
	
	power=(int)pow(2,float(n));
	half_power=power/2;
	rem=r%4;

	switch(rem){
		case 1:
			deny(0,half_power,half_power,power);
			deny(half_power,power,half_power,power);
			break;
		case 2:
			deny(0,half_power,0,half_power);
			deny(half_power,power,half_power,power);
			break;
		case 3:
			deny(half_power,power,0,half_power);
			deny(half_power,power,half_power,power);
			break;
	}
}

//deny a matrix 
void deny(int i_inf,int i_sup,int j_inf,int j_sup){
	
	int i,j;

	for(i=i_inf;i<i_sup;i++){								
		for(j=j_inf;j<j_sup;j++)
			if(pavement[i][j]=='0')
				pavement[i][j]='1';
			else
				pavement[i][j]='0';
	}
}

