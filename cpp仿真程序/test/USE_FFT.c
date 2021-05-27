 
#include<fftw3.h>
#include<complex.h>
 
 #include<stdio.h>
 #include"USE_FFT.h"







 

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
 
 
 
 
 
 void shuchuz(double _Complex *p,int a,int b)
{printf("\n");
for(int i=0;i<a;i++)
{for(int j=0;j<b;j++)
{printf("%f+%fI\t,",creal(p[i*b+j]),cimag(p[i*b+j]));
}
printf("\n");
}

}

 
 