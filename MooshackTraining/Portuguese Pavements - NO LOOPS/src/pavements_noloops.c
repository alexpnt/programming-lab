/*
Portuguese Pavements - NO LOOPS LPA 2013

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

void loop_cpy(int,int,int,int,int);
void loop1(int,int,int,int);
void loop2(int,int,int);
void loop_neg(int,int,int,int,int);
void loop_neg2(int,int,int,int);
void loop_print(int,int,int);
void loop_input();

int main(){

	loop_input();
	return 0;
}

void design(int n){
	
	int half_power,power;

	if(n==0){
		pavement[0][0]='0';
	}
	else{
		design(n-1);

		power=powers[n-1];
		half_power=power/2;
		
		loop_cpy(0,half_power,half_power,0,half_power);
		loop_cpy(half_power,power,0,half_power,half_power);

		loop_neg(half_power,power,half_power,power,half_power);
		
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

	loop1(i_inf,i_sup,j_inf,j_sup);
}

void loop1(int i,int i_sup,int j_inf,int j_sup){

	if(i==i_sup)
		return;
	else
	{
		loop2(i,j_inf,j_sup);
		loop1(i+1,i_sup,j_inf,j_sup);
	}
}

void loop2(int i,int j,int max){

	if(j==max)
		return;
	else{
		pavement[i][j]=pavement[i][j]^1;
		loop2(i,j+1,max);
	}
}

void loop_cpy(int i,int i_sup,int dest,int source,int nbytes){

	if(i==i_sup)
		return;
	else{
		memcpy(pavement[i]+dest,pavement[i-source],nbytes);
		loop_cpy(i+1,i_sup,dest,source,nbytes);
	}
}

void loop_neg(int i,int i_sup,int j_inf,int j_sup,int shiftback){

	if(i==i_sup)
		return;
	else
	{
		loop_neg2(i,j_inf,j_sup,shiftback);
		loop_neg(i+1,i_sup,j_inf,j_sup,shiftback);
	}
}

void loop_neg2(int i,int j,int max,int shiftback){
	if(j==max)
		return;
	else{
		pavement[i][j]=pavement[i-shiftback][j]^1;
		loop_neg2(i,j+1,max,shiftback);
	}
}

void loop_print(int i,int max,int n){
	if(i==max)
		return;
	else{
		fwrite(pavement[i],sizeof(char),(size_t)powers[n-1],stdout);
		putchar('\n');
		loop_print(i+1,max,n);
	}
}

void loop_input(){

	int n,max;

	if(scanf("%d %d",&n,&r)==EOF)
		return;
	else{
		design(n);

		max=powers[n-1];
		loop_print(0,max,n);
		loop_input();
	}
}

