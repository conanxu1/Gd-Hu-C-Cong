#ifdef USE_FFTW

#include<fftw3.h>
#include<complex.h>
#endif

#ifndef MYFUN
#define MYFUN
#include "myfun.h"
#endif








#ifdef USE_FFTW

int fft(double _Complex  * ai,double _Complex  * ao,int N)
{
	 fftw_complex *in, *out;
    fftw_plan p;
   
    int i;
    int j;
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
	
	
        for( i=0; i < N; i++)
    {
            in[i][0] = creal(ai[i]);
            in[i][1] = cimag(ai[i]);
            printf("%6.2f ",in[i][0]);
    }
	
    printf("\n");
	
    p=fftw_plan_dft_1d(N,in,out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed*/
        
	for(j = 0;j < N;j++)
    {
			ao[j]=out[j][0]+out[j][1]*I;
		shuchuz(ao,N,1);
    }
    printf("\n");
    
	
	fftw_destroy_plan(p);
    fftw_free(in); 
    fftw_free(out);
    return 0;
	
	
 }
 
 #endif