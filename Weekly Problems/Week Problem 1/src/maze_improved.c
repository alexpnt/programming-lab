/*
Maze LPA 2013

by Alexandre Pinto
*/

#include <stdio.h>

typedef struct{
    int x;
    int y;
}Point;     /*Ponto*/

int findPath(int,int);
void addPoint(int,int);

char maze[102][102];              /*matriz para armazenar o maze, espaco extra para criar moldura(facilita teste de limites)*/
char mazeHistory[102][102];

Point coordinates[100*100]; /*vetor para guardar coordenadas caso haja um caminho*/
int stackPointer=-1;        /*ponteiro para os pontos da stack*/
int nRows,nColumns;

int main()
{
    int i=0,j=0,z=0,success=0;
    char c;

    while(scanf("%d %d",&nRows,&nColumns)!=EOF)         /*le dados*/
	{
        
        getchar();
        for(i=0;i<nRows;i++){
            while((c=getchar())!=EOF && c!='\n'){
                maze[i+1][j+1]=c;
                mazeHistory[i+1][j+1]=0;                /*limpa o historico anterior*/
                j++;
            }
            maze[i+1][j+1]='\0';
            j=0;
        }

            for(z=1;z<nColumns+1;z++){
                if(maze[1][z]=='\\' || maze[1][z]=='/' || maze[1][z]=='|'){ /*testa cada entrada*/
                    if(findPath(1,z)==1){
                        success=1;
                        z=nColumns+1;

                        for(i=stackPointer;i>0;i--)
                            printf("(%d,%d),",coordinates[i].x,coordinates[i].y);
                        printf("(%d,%d)\n",coordinates[i].x,coordinates[i].y);

                    }
                    stackPointer=-1;  /*volta a colocar a stack virtualmente vazia*/
                }
            }
            if(success==0)
               printf("No Path!\n");
            else{
                success=0;
            }
    }


    return 0;
}

int findPath(int x0,int y0){

    /*caso de paragem: encontrou um caminho*/
    if(x0==nRows)
    {
        addPoint(x0,y0);
        return 1;
    }

    /*deja-vu*/
    if(mazeHistory[x0][y0]==1){
        return 0;
    }
    else
        mazeHistory[x0][y0]=1;


    /*casos em que se pode mover*/
    if(maze[x0][y0]=='|'){
        if(maze[x0+1][y0-1]=='/'){
            if(findPath(x0+1,y0-1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0]=='|'){
            if(findPath(x0+1,y0)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0+1]=='\\'){
            if(findPath(x0+1,y0+1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        return 0;
    }

    else if(maze[x0][y0]=='/'){
        if(maze[x0][y0-1]=='\\'){
            if(findPath(x0,y0-1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0-1]=='/' || (maze[x0+1][y0-1]=='|' && mazeHistory[x0][y0-1]==0)){   /*caso em que nao pode voltar para tras*/
            if(findPath(x0+1,y0-1)==1){                                                     /*verifica se nao vem da esquerda*/
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0]=='\\'){
            if(findPath(x0+1,y0)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0][y0+1]=='\\'){
            if(findPath(x0,y0+1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        return 0;
    }
    else if(maze[x0][y0]=='\\'){
        if(maze[x0][y0-1]=='/'){
            if(findPath(x0,y0-1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0]=='/'){
            if(findPath(x0+1,y0)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0+1][y0+1]=='\\' || (maze[x0+1][y0+1]=='|'&& mazeHistory[x0][y0+1]==0)){
            if(findPath(x0+1,y0+1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        if(maze[x0][y0+1]=='/'){
            if(findPath(x0,y0+1)==1){
                addPoint(x0,y0);
                return 1;
            }
        }
        return 0;
    }

    return 0;
}

void addPoint(int x0,int y0){
    coordinates[++stackPointer].x=x0;       /*acrescenta o ponto a' stack (coordinates)*/
    coordinates[stackPointer].y=y0;
}

