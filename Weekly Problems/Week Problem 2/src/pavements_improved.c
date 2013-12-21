/*
Portuguese Pavements LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>
#include <string.h>

void design(int);
void rotate(int);
void deny(int,int,int,int);

char pavement[1024][1024];
int powers[10]={2,4,8,16,32,64,128,256,512,1024};
int r;

int main(){

	int n,i,max;

	while(scanf("%d %d",&n,&r)!=EOF){
		design(n);

		max=powers[n-1];
		for(i=0;i<max;i++){				/*print output*/
			fwrite(pavement[i],sizeof(char),(size_t)powers[n-1],stdout);
			putchar('\n');
		}
	}

	return 0;
}

void design(int n){
	
	int i,j,half_power,power;

	if(n==0){
		pavement[0][0]='0';
	}
	else{
		design(n-1);

		power=powers[n-1];
		half_power=power/2;
		
		for(i=0;i<half_power;i++){								/*1' quadrant*/
			memcpy(pavement[i]+half_power,pavement[i],half_power);
		}

		for(i=half_power;i<power;i++){							/*3' quadrant*/
			memcpy(pavement[i],pavement[i-half_power],half_power);
		}

		for(i=half_power;i<power;i++){							
			for(j=half_power;j<power;j++){
				pavement[i][j]=pavement[i-half_power][j]^1;
			}
		}

		rotate(n);
	}
}

void rotate(int n){

	int rem,half_power,power;
	
	power=powers[n-1];
	half_power=power/2;
	rem=r%4;

	switch(rem){
		case 1:
			deny(0,half_power,half_power,power);		/*1*/
			deny(half_power,power,half_power,power);	/*4*/
			break;
		case 2:
			deny(0,half_power,0,half_power);			/*2*/
			deny(half_power,power,half_power,power);	/*4*/
			break;
		case 3:
			deny(half_power,power,0,half_power);		/*3*/
			deny(half_power,power,half_power,power);	/*4*/
			break;
	}
}

/*deny a matrix*/ 
void deny(int i_inf,int i_sup,int j_inf,int j_sup){
	
	int i,j;

	for(i=i_inf;i<i_sup;i++){								
		for(j=j_inf;j<j_sup;j++)
			pavement[i][j]=pavement[i][j]^1;
	}
}

