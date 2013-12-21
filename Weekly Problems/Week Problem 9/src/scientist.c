/*
Scientists LPA 2013

by ALexandre Pinto 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NRECTS 1000

typedef struct{
	int xBegin;
	int yBegin;
	int xEnd;
	int yEnd;
}Rectangle;				/*Rectangulo*/

void findArea();
void findPerimeter();
void addActiveRectangle(Rectangle r);
void removeActiveRectangle(Rectangle r);
int calcVerticalDist();
int comparatorXBegin(const void *a, const void *b);
int comparatorXEnd(const void *a, const void *b);
int comparatorY(const void *a, const void *b);

int N;
int N_ACTIVES;			/*numero de quadrados ativos na regiao definida pelas linha vertical atual e anterior*/
int area;
int perimeter;
int n_H;				/*numero de arestas horizontais numa dada regiao ativa*/

Rectangle rectangles[NRECTS];
Rectangle lyingRectangles[NRECTS];
Rectangle activeRectangles[NRECTS];
Rectangle rSortedXBegin[NRECTS];
Rectangle rSortedXEnd[NRECTS];

int main()
{
	int x1,y1,x2,y2,finalArea;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF){
		rectangles[N].xBegin=x1;
		rectangles[N].yBegin=y1;
		rectangles[N].xEnd=x2;
		rectangles[N].yEnd=y2;

		lyingRectangles[N].xBegin=y1;	/*rectangulos transpostos*/
		lyingRectangles[N].yBegin=x1;
		lyingRectangles[N].xEnd=y2;
		lyingRectangles[N].yEnd=x2;
		N++;
	}

	/*calcula a area da uniao dos rectangulos, bem como o perimetro horizontal*/
	memcpy(rSortedXBegin,rectangles,N*sizeof(Rectangle));	
	memcpy(rSortedXEnd,rectangles,N*sizeof(Rectangle));		
	qsort(rSortedXBegin,N,sizeof(Rectangle),comparatorXBegin);	/*ordena rectangulos por x inicial*/
	qsort(rSortedXEnd,N,sizeof(Rectangle),comparatorXEnd);		/*ordena rectangulos por x final*/
	findArea();
	finalArea=area;									
/*
	memcpy(rSortedXBegin,lyingRectangles,N*sizeof(Rectangle));
	memcpy(rSortedXEnd,lyingRectangles,N*sizeof(Rectangle));
	qsort(rSortedXBegin,N,sizeof(Rectangle),comparatorXBegin);
	qsort(rSortedXEnd,N,sizeof(Rectangle),comparatorXEnd);
	findArea();
*/
	printf("%d %d\n",finalArea,perimeter);

	return 0;
}

void findArea(){
	int actual=rSortedXBegin[0].xBegin;
	int next=0;
	int i=0,j=0;
	int delay,verticalPerimeter;

	while(j<N){
		while(i<N && rSortedXBegin[i].xBegin==actual){		/*adiciona os rectangulos que comecam no atual*/
			addActiveRectangle(rSortedXBegin[i]);			/*adiciona rectangulo ativo*/
            i++;
	    }

        while(j<N && rSortedXEnd[j].xEnd==actual) {			/*remove os rectangulos que terminam no atual*/
            removeActiveRectangle(rSortedXEnd[j]);			/*remove rectangulo ativo*/
            j++;
        }

        if(i<N && j<N){										/*encontra a proxima linha vertical (sweep line)*/
            if(rSortedXBegin[i].xBegin<=rSortedXEnd[j].xEnd) {
                next=rSortedXBegin[i].xBegin;
            } else {
                next=rSortedXEnd[j].xEnd;
            }
        }else if(j<N) {
            next=rSortedXEnd[j].xEnd;
        }

        delay=next-actual;									/*distancia(largura) entre a linha vertical actual e a proxima*/
        verticalPerimeter = calcVerticalDist();				/*calcula a distancia vertical*/
        area+= verticalPerimeter*delay;						/*calcula a area de um rectangulo*/	
        perimeter+=n_H*delay;								/*calcula o perimetro horizontal da regiao*/ 
        actual=next;
    }
}

void addActiveRectangle(Rectangle r){				/*adiciona rectangulo*/

	activeRectangles[N_ACTIVES++]=r;
	qsort(activeRectangles,N_ACTIVES,sizeof(Rectangle),comparatorY);
}

void removeActiveRectangle(Rectangle r){		
	int index;

	for(index=0;index<N_ACTIVES;index++){				/*procura pelo rectangulo*/	
		if(activeRectangles[index].xBegin==r.xBegin
			&& activeRectangles[index].xEnd==r.xEnd
			&& activeRectangles[index].yBegin==r.yBegin
			&& activeRectangles[index].yEnd==r.yEnd)
			break;
	}

	activeRectangles[index].yBegin=INT_MAX;				/*remove*/
	qsort(activeRectangles,N_ACTIVES,sizeof(Rectangle),comparatorY);

	N_ACTIVES--;
}

int calcVerticalDist(){

	int verticalL=0;
	int start,end,i=0;
	n_H=0;

	while(i<N_ACTIVES){							/*percorre os rectangulos ativos*/
		start=activeRectangles[i].yBegin;		/*inicio*/
		end=activeRectangles[i].yEnd;			/*fim*/

		 while(i<N_ACTIVES && activeRectangles[i].yBegin<=end){
            if(activeRectangles[i].yEnd>end){
                end=activeRectangles[i].yEnd;
            }
            i++;
        }

        verticalL+=end-start;
        perimeter+=2*verticalL;
        n_H+=2;							/*soma o numero de arestas horizontais contidas nessa regiao*/
	}

	return verticalL;
}

int comparatorXBegin(const void *a, const void *b){		/*comparador quicksort, para ordenar pelo x inicial*/

	Rectangle* r1=(Rectangle*)a;
	Rectangle* r2=(Rectangle*)b;

	return r1->xBegin-r2->xBegin;
}

int comparatorXEnd(const void *a, const void *b){		/*comparador quicksort, para ordenar pelo x final*/
	Rectangle* r1=(Rectangle*)a;
	Rectangle* r2=(Rectangle*)b;

	return r1->xEnd-r2->xEnd;
}

int comparatorY(const void *a, const void *b){			/*comparador quicksort, para ordenar pelo y inicial (y final em caso de empate)*/

	Rectangle* r1=(Rectangle*)a;
	Rectangle* r2=(Rectangle*)b;

	if(r1->yBegin==r2->yBegin)
		return r1->yEnd-r2->yEnd;
	else
		return r1->yBegin-r2->yBegin;
}


