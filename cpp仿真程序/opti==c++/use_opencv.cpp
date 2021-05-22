#ifndef _PRO_H_
#define _PRO_H_
	#include "pro.h"
#endif
 

#define USE_OPENCV
#ifdef USE_OPENCV
#include <opencv2/opencv.hpp>
#include"use_opencv.hpp"
#endif



//递归计算阶乘
long factorial_recursion(int n){
    if(n<=0){
        return 1;
    }else{
        return n * factorial_recursion(n-1);
    }
}

//<---------计算勒让德多项式的根

namespace Legendre{

	double* P_n(int n)
	{

		double* a_n=(double *)malloc((n+1)*sizeof(double) );


		 
		if(n==0)
		{
			 a_n[0]=0;
			 return a_n;
		}
		if(n==1)
		{
			 a_n[0]=0;
			a_n[1]=1;
			return a_n;
		}


		if(n>1)
		{
			double* coef1=(double *)malloc((n+1)*sizeof(double)); 
			double* coef2=(double *)malloc((n+1)*sizeof(double)); 
			double* tm=(double *)malloc((n+1)*sizeof(double)); 
			
			memset(coef1,0,sizeof(double)*(n+1));
			memset(coef2,0,sizeof(double)*(n+1));
			memset(tm,0,sizeof(double)*(n+1));
			
			
			coef1[0]=1;
			coef2[1]=1;
			
			for(int i=1;i<=(n-1);i++)
			{
				for(int oo=0;oo<=i+1;oo++)
				{
					tm[oo]=coef2[oo];
				}
				
				
				for(int j=i;j>=0;j--)
				{
					coef2[j+1]=coef2[j];
				}
				coef2[0]=0;			
				for(int j=i+1;j>=0;j--)
				{
					coef2[j]=(2*i+1.0)*coef2[j]/(i+1.0)-(i)*coef1[j]/(i+1.0);
				}
				
				 for(int j=i+1;j>=0;j--)
				{
					coef1[j]=tm[j];
				}
			}
			
		for(int j=n;j>=0;j--)a_n[j]=coef2[j];
			
		free(coef1);	
		free(coef2);	
		free(tm);	
		coef1=NULL;
		coef2=NULL;
		tm    =NULL;
			
		return a_n;
		}
		
		
		
	return a_n;
	}
	

	
	
	
	
		

		
		
		
		
	//cite:<Spectral/hp Element Methods for CFD>

	
	double Initial_Guess(int i,int m)
	{	return -cos((2*i+1)* 4.0*atan(1.0)/(2*m)    )	;}	
		

	double* Legendre_Root(int m)
	{
		double* a_n=P_n(m);
		double* b_n=dP_n(a_n,m);
		double* xk=(double *)malloc((m)*sizeof(double));	
		
		double r=0,s=0,delta=0;
		double ep=1e-15,Pmab=0,dPmab=0;
		
		// print_vec(a_n,m+1);
		
	
		for(int k=0;k<m;k++)
		{
			r=Initial_Guess(k,m);
			
			if(k>0) r=(r+xk[k-1])/2;
			
			do{
				s=0;
				for(int i=0;i<k;i++)
				{
					s=s+1.0/(r-xk[i]);
				}
				Pmab=Poly_Sub(r,a_n,m);
				dPmab=Poly_Sub(r,b_n,m-1);
				delta=-Pmab/( dPmab-Pmab*s );
				r=r+delta;
				}while(fabs(delta)>ep);
				xk[k]=r;			
			}
			
			sort(xk,xk+m);
			
			free(a_n);
			free(b_n);
 
			a_n=NULL;
			b_n=NULL;
		
			
			return xk;
		}
		
		
		
		//cite:<Ledendre多项式零点的一种求解方法及应用>
		
		double* Legendre_Wk(int m)
		{
			double* wk=(double*)malloc(m*sizeof(double));
			double* xk=Legendre_Root(m);
			double* pn=P_n(m-1);
			double* pnn=P_n(m);			
			double* dpn=dP_n(pnn,m);
			
			double pn1_xk,dpn_xk;
			
			for(int i=0;i<m;i++)
			{
				pn1_xk=Poly_Sub(xk[i],pn,m-1);
				dpn_xk=Poly_Sub(xk[i],dpn,m-1);
				
				wk[i]=2.0/m/pn1_xk/dpn_xk;
				 
			}
		return wk;
		}
 

}






double* dP_n(double* a_n,int N)
{
	double* b_n=(double *)malloc((N)*sizeof(double));	
	for(int i=N-1;i>=0;i--)
	{
		b_n[i]=a_n[i+1]*(i+1);	
	}
	return b_n;
}




//秦九韶算法
double Poly_Sub(double x,double* a_n,int N)
{
	double s=0;
	if(N==0)
	{
		s=a_n[0];
		return s;
	}
	s=a_n[N]*x+a_n[N-1];
	for(int i=N-1;i>=1;i--)
	{
		s=s*x+a_n[i-1];
	}
	return s;
}




