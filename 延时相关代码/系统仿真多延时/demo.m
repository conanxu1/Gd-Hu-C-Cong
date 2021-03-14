close all
clear all
clc
global dimx
global dimu
global N


dimx=2;
dimu=1;

N=2;
A_i=cell(N+1,1);
A_i{1,1}= -ones(dimx,dimx)+0.7*triu(sin(ones(dimx,dimx)))  -10*triu(ones(dimx,dimx))  ;
A_i{2,1}= 0.7*triu(sin(ones(dimx,dimx)))  -6.5*ones(dimx,dimx)  ;
A_i{3,1}=-0.5*triu(ones(dimx,dimx))      -15*ones(dimx,dimx);
B_i=cell(N+1,1);
B_i{1,1}=0.1*ones(dimx,dimu)+[3;1];
B_i{2,1}=0.2*ones(dimx,dimu)+[2;0];
B_i{3,1}=ones(dimx,dimu)-[0.5;0];
taui(1)=0.2;
taui(2)=0.8;
tspan=10;
h=0.5e-3;

global gAi
global gBi
global gtaui
gAi=A_i;
gBi=B_i;
gtaui=taui;




tic
options = ddeset('InitialStep',1e-13,'Jumps',0,'AbsTol',1e-13,'InitialY',mphi(0),'MaxStep' , 2*1e-3  );
sol = dde23(@rea,taui,@mphi,[0, tspan],options);
tt=(1:ceil(tspan/h))*h;
xdata=deval(sol,tt);
save ddedata xdata tt;
toc

soo=load('ddedata.mat')
xdata=soo.xdata;
tt=soo.tt;





[ udata ] = comdata( @myut,[ tt],dimu);
ttdelay=(-round(taui(N)/h):round(taui(N)/h))*h-taui(N);
[ uhis ] = comdata( @myut,[ttdelay],dimu);

[ xhis ] = comdata( @mphi,[ttdelay],dimx);







