/*
Scheduling conferences LPA 2013 

by Alexandre Pinto
*/

#include <stdio.h>
#define EVENTOS 150000
int main()
{
    
    int n_eventos,i,j,temp_max=0;
    int matriz[EVENTOS][2];
    
    scanf("%d",&n_eventos);
    
    for(i=0;i<n_eventos;i++){
        scanf("%d %d",&matriz[i][0],&matriz[i][1]);
        matriz[i][1]=matriz[i][1]-1;
        if(matriz[i][1]>temp_max){
            temp_max=matriz[i][1];
        }
    }
    
    int contador=0,maior_contador=0;
    for(i=0;i<temp_max;i++){
        for(j=0;j<n_eventos;j++){
            if(i >= matriz[j][0] && i <=matriz[j][1]){
                contador++;
            }
        }
        if(contador>maior_contador){
            maior_contador = contador;
        }
        contador=0;
    }
    printf("%d\n",maior_contador);
    return 0;
}


