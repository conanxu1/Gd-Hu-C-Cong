#ifndef _PRO_H_
#define _PRO_H_
#include "pro.h"
#endif

 


// extern int N;

typedef struct
{
int dimx;
int dimu;
double t0;
double tf;
}Pro_Scale;







namespace Pro1{
Rn my_fxut(Rn x ,      Rn u     ,double        t );
R my_opt_phi(Rn xt0 ,     double t0, Rn xtf ,     double tf );
R my_opt_L(Rn x ,      Rn u     ,double        t );

Rn pLpx(Rn x ,      Rn u     ,double        t,int dimx,int dimu );
Rn pLpu(Rn x ,      Rn u     ,double        t ,int dimx,int dimu);
Rn myut(double t);
}



