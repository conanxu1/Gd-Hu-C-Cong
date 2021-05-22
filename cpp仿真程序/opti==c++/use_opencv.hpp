namespace Legendre{
double* P_n(int n);
double Initial_Guess(int i,int m);
double* Legendre_Root(int m);
double* Legendre_Wk(int m);

double* LGL_Root(int m);
double* LGL_Wk(int m);
double* LGL_Dki(int m);

}



double* dP_n(double* a_n,int N);
double Poly_Sub(double x,double* a_n,int N);





