#ifndef MYFUN
#define MYFUN
#include "myfun.h"
#endif
// // #include <stdio.h>
// // #include <string.h>
// // #include <stdlib.h>
// // #include <complex.h>
// // #include <math.h>


void my_inv(double *or_A,int dim,double* A )
{
memcpy(A,or_A,dim*dim*sizeof(double));	
	
int s=dim;
int ipiv[s];
int info;
info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR,s,s,A,s,ipiv);
info = LAPACKE_dgetri(LAPACK_ROW_MAJOR,s,A,s,ipiv);
	
}	


//step1

int compute_active_set(
		double *Ae,		//系数
		double *be,		//b   等式约束
		double *Ai,
		double *bi,		////b   不等式约束
		int e,			//等式个数
		int ie,			//不等式个数
		double *xk,
		int dim,		//问题的维数
		int *Ak,
		double t,		//大M法的t
		double epsilon //精度
		)
{
	
	double val=0;
	int id=0,active_set_num=0;
	for(int i=0;i<e;i++)
	{
		 
		val=0;
		for(int j=0;j<dim;j++)
		{
			 val+=Ae[j*e+i]*xk[j];
		}
		val=t+val-be[i];
		if(val>=0 && val<=epsilon)
		{
			Ak[id]=i;
			id++;
			active_set_num++;
		}
	}
	
	for(int i=0;i<e;i++)
	{
	 
		val=0;
		for(int j=0;j<dim;j++)
		{
			 val-=Ae[j*e+i]*xk[j];
		}
		val=t+val+be[i];
		if(val>=0 && val<=epsilon)
		{
			Ak[id]=e+i;
			id++;
			active_set_num++;
		}
	}
	
	for(int i=0;i<ie;i++)
	{
		
		val=0;
		for(int j=0;j<dim;j++)
		{
			 val+=Ai[j*ie+i]*xk[j];
			 
		}
		printf("===%lf\n",val);
		val=t+val-bi[i];
		if(val>=0 && val<=epsilon)
		{
			printf("ii%d\n",i);
			Ak[id]=2*e+i;
			id++;
			active_set_num++;
		}
	}
	
	
	

	return active_set_num;

}
	

//step2
//不破坏A，返回A=LL^T,L为下三角
void Cholesky(double* A,int n,double* L)
{
	 int matrix_order = LAPACK_ROW_MAJOR;
    char uplo = 'L';
	int info;
	memcpy(L,A,n*n*sizeof(double));
	LAPACKE_dpotrf( matrix_order,  uplo,  n, L, n   );
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
		L[i*n+j]=0;
}

Solve_KKT_GhAb(double* G,
						  double* h,
						  double* A,
						  double* b
						  int dim,
						  int e_num)
{
	
double* L=(double*)malloc(dim*dim*sizeof(double));
Cholesky(A,dim,L);
double* inv_G=(double*)malloc(dim*dim*sizeof(double));
my_inv(G,dim,inv_G);
 

							  
 }




//step3

//step4


//部分二次规划见myqp


int erci(
		double *H,		//hessian/2
		double *h,		//原问题grad
		double *be,		//b   等式约束
		double *Ae,		//系数
		double *bi,		////b   不等式约束
		double *Ai,
		int dim,		//问题的维数
		int e,			//等式个数
		int ie,			//不等式个数
		double *xk,
		double *lam)
{
	//x^THx+h^Tx
	//Ae^Tx=be
	//Ai^Tx>=bi
	//<数值最优化方法>-高立
	//Ae[i*dim+j]=a_ij
	
	double *G=(double *)malloc(dim*dim*sizeof(double));
	cblas_daxpby(dim*dim, 2, H, 1, 0, G, 1);
	
	//step1:k=0确定x_0
	int k=0;
	//step1:确定A_0
	//按照 高立 P232 (8.19)后续采用大M法
	//序号按(8.19)式 0,1,...,(2e+ie)排列,即只有不等式约束
	
	int *Ak=(int *)malloc((2*e+ie+1)*sizeof(int));
	int num_active_set=0;
	double t=0,epsilon=1e-10;
	
	num_active_set=compute_active_set(Ae,be,Ai,bi,e,ie,xk,dim, Ak, t ,epsilon);
		
	//step2 求解系统(8.18)(8.15)

	
	
	
	
	
	
	
	
	
	
	
	
	
	return 1;
}	
	
	
/*
	
	//等式约束
	//[G,-A;-A' 0] A等式

	int nu;
	
	int qinum=0;
	double ep=1e-6;
	//指标集 自动要求等式约束 
	
	int *tp=(int *)malloc((ie)*sizeof(int));
	//A0>=0
	double *tg=(double *)malloc(dim*sizeof(double));
	double *zuoyong=(double *)malloc((e+ie)*dim*sizeof(double));
	double *tb=(double *)malloc((e+ie)*sizeof(double));
	double alpha=0;
	double *dk=(double *)malloc(dim*sizeof(double));
	double *tbi=(double *)malloc(ie*sizeof(double));
	double test;
	double *ait=(double *)malloc(dim*sizeof(double));
	double zuixiao;
	int index;

	memset(A0,-1,ie*sizeof(int));
	memcpy(tb,be,e*sizeof(double));
	memcpy(zuoyong,Ae,dim*e*sizeof(double));
	memcpy(tg,h,dim*sizeof(double));
	memcpy(tbi,bi,ie*sizeof(double));






	cblas_dgemm(CblasRowMajor, CblasNoTrans,CblasNoTrans, ie, 1,dim, 1,Ai, dim,xk, 1,-1,tbi,1 );



	index=0;  //借用


	 

 



	for(int i=0;i<ie;i++)
	{
		if(tbi[i]<ep) 
				{	
			
					qinum+=1;
					A0[qinum-1]=i;
					for(int tt=0;tt<dim;tt++)
					{zuoyong[dim*e+(qinum-1)*dim+tt]=Ai[dim*i+tt];
				
				
				
					}
					
				}
	}



	//定义其作用集 函数 由初始点起作用集





	 

	//xk=tg

	

	//printf(" G\n");
	//shuchud(G,dim,dim);	

	int ho=0;


	//////diedai
	while(1)
	{
	ho++;
	printf("\n%d      >>>>>>>>>>>>>>>>>>>>>>>>>>>>d>>>>>>>>>>>>\n",ho);

	printf(" dangqiandianxk\n");
	shuchud(xk,dim,1);	
 




		cblas_daxpby(dim, 1,h, 1, 0, tg, 1);
		
		cblas_dgemm(CblasRowMajor, CblasNoTrans,CblasNoTrans, dim, 1,dim, 1,G, dim,xk, 1,1,tg,1 );	
		


		memset(tb,0,(e+ie)*sizeof(double));

		// printf("\n++...G \n");
		// shuchud(G,dim,dim);
		
		// printf("ziwenti...zuoyong \n");
		// shuchud(zuoyong,e+qinum,dim);
		// printf("ziwentitidu...\n");
		// shuchud(tg,dim,1);
		//printf("++... %d\n",e+qinum);
		//printf("..%lf..\n",tb[0]);




		myqp(H,zuoyong,tg,tb,dim,(e+qinum));

		memcpy(dk,tg,dim*sizeof(double));
			
		 printf("++...dk\n");
		 shuchud(tg,dim,1);	
		// printf("++...lam_ki\n");
		// shuchud(tb,e+qinum,1);	
		// printf("++...zuoyong \n");
		// shuchud(zuoyong,e+qinum,dim);

			

	printf("norm\n%15.15f",cblas_dasum(dim, tg,1));
		
		//dk=0
		if(cblas_dasum(dim, tg,1)<ep)
		{

				printf("\n--------------------------------------欧克\n");
				
			zuixiao=0;
			index=-1;
			for(int i=0;i<qinum;i++)
			{	
				if(tb[e+i]<zuixiao)
					{index=i;
					zuixiao=tb[e+i];
					}	
			}
			if(index>=0)
			{printf("index%d\n",index);
				if(index<qinum-1)
				{
				A0[index]=A0[qinum-1];
				A0[qinum-1]=-1;
				for(int tt=0;tt<dim;tt++)
					{zuoyong[e*dim+index*dim+tt]=zuoyong[e*dim+ (qinum-1)*dim+tt];
					//用最后的覆盖
					}
				qinum=qinum-1;
				}
			 else
				{A0[qinum-1]=-1;
				qinum=qinum-1;}	
			}
			else{

			

			for(nu=0;nu<e;nu++)
			{lam[nu]=tb[nu];
			
			}
			

			for(nu=0;nu<ie;nu++)
			{printf("???????%d",e+nu);
			lam[e+nu]=0;
			}
			
			for(nu=0;nu<qinum;nu++)
			{
			lam[e+A0[nu]]=tb[e+nu];
			}

			
				// shuchud( ,e+qinum,1);

	// ///gai x0weihao			
				
				printf("ffinishd\n");
				return 1;
			}
		}
		else
		{	//alpha xk

			index=-1;
			zuixiao=1;
			alpha=1;
			memset(tp,0,ie*sizeof(int));
			for(int j=0;j<qinum;j++)
			{
				if(A0[j]>=0)
				{tp[A0[j]]=1;}
			}
			// printf("\n\n\n\n\n%d\n\nqiz\n",ie);
			// shuchui(A0,ie,1);

			// printf("bukexingji....\n");
			// shuchui(tp,ie,1);
			//alpha测试一遍
			for(int j=0;j<ie;j++)
			{	
				//不属于的
				if(tp[j]<1)
				{for(int tt=0;tt<dim;tt++)
				{ait[tt]=Ai[dim*j+tt];}
				
				

				if(cblas_ddot(dim, ait, 1, dk,1)<0)
				{

					test=(bi[j]-cblas_ddot(dim, ait, 1, xk,1));
					test=test/cblas_ddot(dim, ait, 1, dk,1);
					//printf("%lf\n",test);		

			if((test<zuixiao))
						{zuixiao=test;
						index=j;}
				}}
			printf("\n.dangqian.%lf..alpha",zuixiao);
			}


	 




			
			cblas_daxpby(dim,zuixiao,dk,1,1,xk,1);
		/////////



			if(index>-1)
				{qinum=qinum+1;
				A0[qinum-1]=index;
				for(int tt=0;tt<dim ;tt++)
				{zuoyong[e*dim+(qinum-1)*dim+tt]=Ai[index*dim+tt];}
				
				}
		}

		
	}
			





	free(ait);
	free(dk);
	free(tb);
		
		
	free(tg);
	free(zuoyong);
	free(A0);
	free(G);


	
*/