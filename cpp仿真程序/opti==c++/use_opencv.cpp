#ifndef _PRO_H_
#define _PRO_H_
	#include "pro.h"
#endif
 
using namespace cv;




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

double an(int n)
{
	double rs=0;
	for(int i=1;i<=n;i++)
	{
		rs=rs*((n+i)/2.0)/i;
	}
	return rs;
}






void test()
{
Mat coef= (Mat_ <double>(3, 1) << 1, - 2, 1 );
Mat roots;
solvePoly(coef, roots);
cout<< typeid(roots).name();
cout << "Roots: channels = " << roots.channels() << " , values = " << roots << ".";
}

}