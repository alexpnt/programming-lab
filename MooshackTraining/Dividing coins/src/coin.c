/*
Dividing coins LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

#define NCOINS 101
#define MAXVAL 25001

int S[NCOINS];
int M[NCOINS][MAXVAL];

int subset(int,int);

int main()
{
    int nTests,i,j,z,n,m,diff,ret;

    while(scanf("%d",&nTests)!=EOF){
        for(i=0;i<nTests;i++){

            m=0;
            ret=scanf("%d",&n);
            for(j=1;j<=n;j++){
                ret=scanf("%d",&S[j]);
                m+=S[j];
            }

            subset(n,m/2);              /*verifica se existe um subconjunto da share ideal*/
            for(z=m/2;z>=0;z--){
                if(M[n][z]){               /*procura a share mais proxima*/
                    diff=(m-z)-z;
                    printf("%d\n",diff);
                    break;
                }

            }


        }
    }
    return 0;
}

int subset(int n, int m)
{
    int i, j;
    for(i=0; i<=n; i++) {
        M[i][0] =1;
    }

    for(j=1; j<=m; j++) {
        M[0][j] = 0;
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(S[i] > j) {
                M[i][j] = M[i-1][j];
            }
            else {
                M[i][j] = M[i-1][j] || M[i-1][j-S[i]];
            }
        }
    }

    return M[n][m];
}
