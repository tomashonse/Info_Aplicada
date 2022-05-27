#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	int n;
	double *coeficiente;
} Polinomio;

Polinomio * creaPolinomio(int orden){
	Polinomio *p=NULL;
	p=(Polinomio*)malloc(sizeof(Polinomio));
	p->n=orden;
	p->coeficiente=(double*)calloc((orden+1),sizeof(double));
	return p;
}

void setCoef(int n, double c, Polinomio * P)
{
	if(n<=P->n){
		P->coeficiente[n]=c;
	}
}

double getCoef(int n, Polinomio * P){
	return P->coeficiente[n];
}

double especializa( double x, Polinomio * P ){
	double suma=0;
	int i;
	for(i=0;i<=P->n;i++)
		suma+=P->coeficiente[i]*pow(x,i);
	return suma;
}

Polinomio * sum( Polinomio *p1, Polinomio *p2){
	Polinomio *ps, *mayor;
	int orden,i,menor;
	if(p1->n>=p2->n){
		orden=p1->n;
		menor=p2->n;
		mayor=p1;
	}
	else{
		orden=p2->n;
		menor=p1->n;
		mayor=p2;
	}
	ps=creaPolinomio(orden);
	for(i=0;i<=menor;i++)
		ps->coeficiente[i]+=p1->coeficiente[i]+p2->coeficiente[i];
	for(i=menor+1;i<=mayor->n;i++)
		ps->coeficiente[i]+=mayor->coeficiente[i];
	return ps;
}

Polinomio * mult( Polinomio *p1, Polinomio *p2){
	Polinomio *ps;
	int i, orden,j;
	orden=p1->n+p2->n;
	ps=creaPolinomio(orden);
	for(i=0;i<=p1->n;i++)
		for(j=0;j<=p2->n;j++)
			ps->coeficiente[i+j]+=(p1->coeficiente[i])*(p2->coeficiente[j]);
	return ps;
}

void destruyePolinomio( Polinomio *p ){
	free(p->coeficiente);
	free(p);
}

Polinomio * deriv( Polinomio *p ){
	Polinomio *pd;
	int orden,i;
	orden=p->n;
	pd=creaPolinomio(orden);
	for(i=orden;i>=1;i--)
		pd->coeficiente[i-1]=i*p->coeficiente[i];
	return pd;
}

double ceropol(Polinomio *p, double a, double b, double epsilon){
	double c, pa, pc, pb;
	while(fabs(a-b) >= epsilon){
		c = (a+b)/2;
		pa = especializa(a, p);
		pb = especializa(b, p);
		pc = especializa(c, p);
		if(pc == 0){
			return c;
		}
		if(pa*pc > 0){
			a = c;
		}
		if(pa*pc < 0){
			b = c;
		}
	}
	return c;
}



void E2_main()
{
	Polinomio *q=creaPolinomio(2);
	setCoef(0,-4,q);
	setCoef(1,-11,q);
	setCoef(2,3,q);
	printf("%lf\n",especializa(1.0,q));

}
