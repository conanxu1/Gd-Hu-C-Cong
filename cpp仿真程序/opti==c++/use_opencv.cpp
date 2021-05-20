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
	
	
	
	

void Polynomial_Root(double* coef,int n)
{
cv::Mat coefn= (cv::Mat_ <double>(n, 1)   );
uchar* datar = coefn.data; 

for(int i=0;i<=n;i++)
{
datar[i*coefn.step+0]  = coef[i];
}

cv::Mat roots;
cv::solvePoly(coefn, roots);
cout<< typeid(roots).name();
cout << "Roots: channels = " << roots.channels() << " , values = " << roots << ".";
}

}





