#ifndef _PRO_H_
#define _PRO_H_
	#include "pro.h"
#endif
 
using namespace cv;

void test()
{
  
  
  

Mat coef= (Mat_ <double>(3, 1) << 1, - 2, 1 );
Mat roots;
solvePoly(coef, roots);
cout<< typeid(roots).name();
cout << "Roots: channels = " << roots.channels() << " , values = " << roots << ".";

}
