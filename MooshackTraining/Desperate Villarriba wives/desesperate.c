#include <stdio.h>
#include <stdlib.h>

typedef struct {
int a;
int b;
int ocupado;  /* 0 -livre */
} Peca;

int nPecas, nJog;
Peca matriz[7][8];
int best=0;


void calcula(int valor, int jog, int len)
{
    int i;

    if(len > best) {
        best = len;
    }


    for(i=0; i<nPecas; i++) {
        if(matriz[jog][i].a == valor && matriz[jog][i].ocupado==0) {
            matriz[jog][i].ocupado=1;
            calcula(matriz[jog][i].b, (jog+1)%nJog, len+1);
            matriz[jog][i].ocupado=0;
        }
        if(matriz[jog][i].a != matriz[jog][i].b) {
            if(matriz[jog][i].b == valor && matriz[jog][i].ocupado == 0) {
                matriz[jog][i].ocupado=1;
                calcula(matriz[jog][i].a, (jog+1)%nJog, len+1);
                matriz[jog][i].ocupado=0;
            }
        }
    }
    return;

}


int main()
{
    int i,j;

    while (scanf("%d", &nJog) != EOF)
    {
        best=0;
        scanf("%d", &nPecas);
        for (i=0; i<nJog; i++) {
            for(j=0; j<nPecas; j++)
            {
                scanf("%d %d",&matriz[i][j].a, &matriz[i][j].b);

            }
        }

        for(i=0; i<nPecas; i++) {
            matriz[0][i].ocupado=1;
            calcula(matriz[0][i].a, 1, 1);
            matriz[0][i].ocupado=0;
            if(matriz[0][i].a != matriz[0][i].b)
                matriz[0][i].ocupado=1;
                calcula(matriz[0][i].b, 1, 1);
                matriz[0][i].ocupado=1;
            
        }

    }

    printf("%d\n",best);

    return 0;
}


