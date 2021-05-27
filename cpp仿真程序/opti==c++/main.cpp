#ifndef _PRO_H_
#define _PRO_H_
	#include "pro.h"
#endif

#ifndef _EX1_H_
#define _EX1_H_
#include "ex1.h"
#endif

#define USE_OPENCV
#ifdef USE_OPENCV
#include <opencv2/opencv.hpp>
#include"use_opencv.hpp"
#endif







int main()
{

double x=7;
double ann[]={6,5,4,3};


cout<<"hhh";
double* dp=Legendre::Legendre_Root(6);
cout<<"hhh";



print_mat(dp,6,1); 
free(dp);
dp=NULL;

cout<<"-----\n";
dp=Legendre::LGL_Root(19);
print_mat(dp,20,1); 
free(dp);
dp=NULL;



dp=Legendre::LGL_Wk(2);
print_mat(dp,3,1); 
free(dp);
dp=NULL;


double* tDki=Legendre::LGL_Dki(2);
print_mat(tDki,3,3);
 
free(tDki);
tDki=NULL;


//-------------------------------


Pro_Scale* Ex1_Scale;
Pro_Scale Ex1_S;
Ex1_Scale=&Ex1_S;

Ex1_Scale->dimx=2;
Ex1_Scale->dimu=1;
Ex1_Scale->t0=0;
Ex1_Scale->tf=2;



double* da=Legendre::P_n(5);


for(int i=0;i<=5;i++)
{
cout<<da[i]<<endl;
}
cout<<endl;

//Legendre::Polynomial_Root(da,5);


//<---欧拉法示例
double ttA[2*2]={1,2,3,4};
double ttB[2*1]={-2,1};
double tx0[2]={1,1};
Rmn A=Rmninit(Ex1_Scale->dimx,Ex1_Scale->dimx);
Rmn B=Rmninit(Ex1_Scale->dimx,Ex1_Scale->dimu);
Rn x0=Rninit(Ex1_Scale->dimx);
Rmn_copy(ttA,A,Ex1_Scale->dimx,Ex1_Scale->dimx);
Rmn_copy(ttB,B,Ex1_Scale->dimx,Ex1_Scale->dimu);
Rn_copy(tx0,x0,Ex1_Scale->dimx);
Euler_Ode_Sol hSol(Ex1_Scale->dimx,Ex1_Scale->dimu,Ex1_Scale->t0,Ex1_Scale->tf,10000000);
hSol.set(A,B,Pro1::myut,x0 );
hSol.sol( );
//--->





//test();







//<-------------------------------
		
		double tol=1e-8;
		int dimx=2;
		int dimu=1;
		Pro mypro(dimx,dimu,0,1,1,1);
		
		mypro.set_daef(Pro1::my_fxut);
		mypro.set_opt_int(Pro1::my_opt_L);
		mypro.set_opt_phi(Pro1::my_opt_phi);
		mypro.set_opt_pLp(Pro1::pLpx,Pro1::pLpu);

	 
		
		// // // // // // // // // // //cout<<mypro.t0;
		
		
		// // // Sol mysol(&mypro);
		// // // mysol.set();
		// // // mysol.display()		;
		// // // mysol.sol(N);
		
	
		

		// // // Rn th=Rninit(dimx*(N+1)+dimu*(N+1)+2);
		// // // for(int i=0;i<(dimx*(N+1)+dimu*(N+1)+2);i++)
		// // // {
			// // // th[i]=i;	
		// // // }
		

			
	// // // mysol.hk_th(th,0);
	
  
	// // // int	NN=3;
	// // // ga_opti myga(dimx,NN,10);
	
	// // // Rn lb =Rninit(dimx);
	// // // Rn ub =Rninit(dimx);
	// // // for(int i=0;i<dimx;i++)
	// // // {
		// // // lb[i]=-1;
		// // // ub[i]=1;
	// // // }

	// // // myga.set_lbub(lb,ub);
	// // // myga.initialize();
	// // // myga.chooose();

//------------------------->



	
	return 1;
}



// void fk(Rn a)
// {
	// a[0]=1;
// }	
	



/*
MatrixXd* CC;
MatrixXd  AA(5,5);

double BB[4]={1,1,1,1};

cout<<"\n------>\n"<<sizeof(AA);



cout<<"\n======>\n"<<sizeof(BB);
cout<<"\n===CC=>\n"<<sizeof(CC);*/
