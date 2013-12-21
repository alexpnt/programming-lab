/*
Polygons have ears! LPA 2013

by Alexandre Pinto 

References:
Curve orientation: http://en.wikipedia.org/wiki/Curve_orientation
Barycentric coordinate system: http://en.wikipedia.org/wiki/Barycentric_coordinate_system
*/

#include <stdio.h>

typedef struct{
	int x;
	int y;
}Point;				/*Um ponto*/

int t;				

Point points[1002];

int isConvex(Point b,Point a,Point c);
int isEar(Point,Point,Point);
int PointInTriangle(Point,Point,Point,Point);

int main(){

	int i,counter=0;

	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d %d",&points[i].x,&points[i].y);			/*le input*/
	}
	points[0]=points[t];									/*cria ciclo para dar jeito na analise 3 a 3*/
	points[t+1]=points[1];									/*o primeiro e ultimo vertice sao casos especiais*/

	for(i=1;i<=t;i++){
		if(isConvex(points[i-1],points[i],points[i+1])){		/*vertice convexo pq det(O)>0*/
			if(isEar(points[i-1],points[i],points[i+1]))
				counter++;
		}
	}
	
	printf("%d\n",counter);
	return 0;
}

int isConvex(Point b,Point a,Point c){
	int det;

	det=(b.x*c.y+a.x*b.y+a.y*c.x)-(a.y*b.x+b.y*c.x+a.x*c.y);	/*calculo do determinante*/
	printf("%d\n",det);

	return det>0;
}
int isEar(Point b,Point a,Point c){

	int i;

	for(i=1;i<=t;i++){
		if(PointInTriangle(points[i],b,a,c))	/*verifica se o ponto esta dentro do triangulo [ABC]*/
			return 0;
	}

	return 1;		/*nao existe nenhum ponto dentro do triangulo*/
}


int sign(Point p1, Point p2, Point p3)
{
  return (p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y);		/*calcula o produto externo*/
}																/*para saber de que lado do semi-plano criado pela aresta o ponto esta*/	

int PointInTriangle(Point pt, Point v1, Point v2, Point v3)
{
  int b1,b2,b3;

  b1 = sign(pt,v1,v2)<0;			/*PB*BA*/
  b2 = sign(pt,v2,v3)<0;			/*PA*CA*/
  b3 = sign(pt,v3,v1)<0;			/*PC*BC*/

  return ((b1 == b2) && (b2 == b3));	/*o mesmo sinal, logo esta dentro do triangulo*/
}
