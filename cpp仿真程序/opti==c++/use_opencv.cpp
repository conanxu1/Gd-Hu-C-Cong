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

		double* rs=(double *)malloc((n+1)*sizeof(double) );


		 
		if(n==0)
		{
			 rs[0]=0;
			 return rs;
		}
		if(n==1)
		{
			 rs[0]=0;
			rs[1]=1;
			return rs;
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
			
		for(int j=n;j>=0;j--)rs[j]=coef2[j];
			
		return rs;
		}
		
		
		
	return rs;
	}
	





// // // void test()
// // // {
// // // Mat coef= (Mat_ <double>(3, 1) << 1, - 2, 1 );
// // // Mat roots;
// // // solvePoly(coef, roots);
// // // cout<< typeid(roots).name();
// // // cout << "Roots: channels = " << roots.channels() << " , values = " << roots << ".";
// // // }

}