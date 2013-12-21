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
            if(guestNumber>0 && count(man.begin(),man.end(),guestNumber)<=1)
                man.push_back(guestNumber);
            else if(guestNumber<0 && count(woman.begin(),woman.end(),guestNumber)<=1)
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

    unsigned int i,j,z;
    int sum;

    for(z=0;z<woman.size();z++){
        if(man[(int)man.size()-1]>=woman[z] || man[(int)man.size()-2]>=woman[z])
            continue;
         for(i=0;i<man.size();i++){
            for(j=i+1;j<man.size();j++){
                if(man[i]>=woman[z] || man[j]>=woman[z])
                   i=man.size();
                else{
                    sum=man[i]+man[j];
                    if(sum==woman[z])
                        return 1;
                }
            }
        }
    }

    for(z=0;z<man.size();z++){
         if(woman[(int)woman.size()-1]>=man[z] || woman[(int)woman.size()-2]>=man[z])
            continue;
         for(i=0;i<woman.size();i++){
            for(j=i+1;j<woman.size();j++){
                if(woman[i]>=man[z] || woman[j]>=man[z])
                   i=woman.size();
                else{
                    sum=woman[i]+woman[j];
                    if(sum==man[z])
                        return 1;
                }
            }
        }
    }

    return 0;
}