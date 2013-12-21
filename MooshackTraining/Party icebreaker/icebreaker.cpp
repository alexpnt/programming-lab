/*
Party icebreaker LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>

using namespace std;

int find();

vector<int> man;
vector<int> woman;  

int main()
{
	int nlines=0,i,guestNumber;

    while(scanf("%d",&nlines)!=EOF)
    {
    	for(i=0;i<nlines;i++){
            scanf("%d",&guestNumber);
            if(guestNumber>0 && binary_search(man.begin(),man.end(),guestNumber)==false)
                man.push_back(guestNumber);
            else if(guestNumber<0 && binary_search(woman.begin(),woman.end(),abs(guestNumber))==false))
                woman.push_back(abs(guestNumber));
        }
        scanf("%d",&guestNumber);

        sort(man.begin(),man.end());
        sort(woman.begin(),woman.end());

        if(find()==1)
            printf("Fair\n");
        else
            printf("Rigged\n");

        man.erase(man.begin(),man.end());
        woman.erase(woman.begin(),woman.end());
    }

	return 0;
}

int find(){

    unsigned int i,j;
    int sum;

    for(i=0;i<man.size();i++){
        for(j=i+1;j<man.size();j++){

            sum=man[i]+man[j];

            if(binary_search(woman.begin(),woman.end(),sum)){
                return 1;
            }
        }
    }

    for(i=0;i<woman.size();i++){
        for(j=i+1;j<woman.size();j++){
            
            sum=woman[i]+woman[j];

            if(binary_search(man.begin(),man.end(),sum)){
                return 1;
            }
        }
    }

    return 0;
}

