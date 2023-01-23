#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <complex.h>



#ifndef MYFUN
#define MYFUN
#include "myfun.h"
#endif





 

int main()
{

	double H[2*2]={0.5,0.0,
								0.0,0.5};
	double h[2]={-3,
						   -2};
	double *be;
	double *Ae;

	double bi[5]={-3,-4,-2,0.0,0.0};

	double Ai[2*5]={0.0, -1, -1,	1,	0,           
								-1, -1, 	0, 0,	1};


	int e=0;
	int ie=5;
	int dim=2;

	int* Ak=(int *)malloc((2*e+ie+1)*sizeof(int));
	
	memset(Ak,0,sizeof(Ak));

	double epsilon=1e-10;
	double t=0;
	double *lam;

	// lam=cshi(e+ie);
	double xk[2]={0,
							3};
	 
	erci(H,h,be,Ae,bi,	Ai,dim,e,ie,	xk,lam );
 
 
 
 
	double Q[3*3]={2,0.0,1.0,	
							0.0,5,2.0,
							1.0,2.0,2};
	double L[3*3];
	Cholesky(Q,3,L);


	return 0;
}
 
 
 


