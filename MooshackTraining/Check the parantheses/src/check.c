/*
Check the parantheses! LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[128];

int check(char*);

int stack_pointer=-1;
char stack[128];

int main()
{
	int nlines=0,i,j=0;
	char c;

	scanf("%d",&nlines);

	getchar();
	for(i=0;i<nlines;i++){
		while((c=getchar())!=EOF && c!='\n'){
			string[j++]=c;
		}
		string[j]='\0';

		if(check(string))
			printf("Yes\n");
		else
			printf("No\n");

		j=0;
	}

	return 0;
}

int check(char* string){

    int i,len,result=0;

    len=strlen(string);

    for(i=0;i<len;i++){
      
    	if(string[i]=='('){
    		stack[++stack_pointer]='(';
    	}
    	else if(string[i]==')'){
    		if(stack[stack_pointer]=='('){
    			stack[stack_pointer--]='\0'; 
    		}
    		else if(stack[stack_pointer]==')' || stack[stack_pointer]=='['){
    			for(i=0;stack[i] && i<len ;i++){                /*clean*/ 
			        stack[i]='\0';
			        string[i]='\0';
				}
    			stack_pointer=-1;
    			return 0;
    		}
    		else if(stack[stack_pointer]==']')
    			stack[++stack_pointer]=')';
			else{
    			for(i=0;stack[i] && i<len ;i++){                /*clean*/ 
			        stack[i]='\0';
			        string[i]='\0';
				}
    			stack_pointer=-1;
    			return 0;
    		}
    	}
    	else if(string[i]=='['){
			stack[++stack_pointer]='[';
    	}
    	else if(string[i]==']'){
    		if(stack[stack_pointer]=='['){
    			stack[stack_pointer--]='\0'; 
    		}
    		else if(stack[stack_pointer]==']' || stack[stack_pointer]=='('){
    			for(i=0;stack[i] && i<len ;i++){                /*clean*/ 
			        stack[i]='\0';
			        string[i]='\0';
				}
    			stack_pointer=-1;
    			return 0;
    		}
    		else if(stack[stack_pointer]==')')
    			stack[++stack_pointer]=']';
    	}
    	else{}
    }

    if(stack_pointer==-1)
        result=1;

    for(i=0;stack[i] && i<len ;i++){                /*clean*/ 
        stack[i]='\0';
        string[i]='\0';
	}

    stack_pointer=-1;

    return result;
}
