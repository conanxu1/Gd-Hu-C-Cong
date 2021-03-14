close all
clear all
clc

N=1
dimx=3
 
 
A_i{1,1}= -eye(dimx,dimx) -sin(0.5);      
A_i{2,1}= -eye(dimx,dimx)-1*sin(eye(dimx,dimx));
tau_i(1)=0.7;


[ W,tnew,xnew ] =numWv2( A_i,tau_i,N)
 
 

bbeta=0;
for i=1:(N+1)
    bbeta=bbeta+norm(A_i{i,1});
end
pp=@(s)Pzf(gammat(s,bbeta),A_i,tau_i,N);
ytau=@(s)imag( Pzf(gammat(s,bbeta),A_i,tau_i,N)) ;

% % % for i=1:length(tnew)
% % %    ytau(tnew(i)) 
% % % end




