function [ W,tnew,xnew ] = numWv2( A_i,tau_i,N)
%多初始点加密 求解
%个数与fendianh的个数有关



bbeta=0;
for i=1:(N+1)
    bbeta=bbeta+norm(A_i{i,1});
end


pp=@(s)Pzf(gammat(s,bbeta),A_i,tau_i,N);
xtau=@(s)real( Pzf(gammat(s,bbeta),A_i,tau_i,N)) ;
ytau=@(s)imag( Pzf(gammat(s,bbeta),A_i,tau_i,N)) ;


% % % options = optimset('Display', 'iter');


fendianh=0.0001;
i=1;
for tt0=0:fendianh:1
    
    % %     test=fzero(ytau,  tt0   );
    % % %     if abs(ytau(test))<1e-2
    % % %         zeropt(i) =test ;
    % % %         i=i+1;
    % % %     end
    test=fzero(ytau,  tt0   );
    zeropt(i) =test ;
    i=i+1;
    
end

%去除相近点
tnew=sort(zeropt);

 
id=1:length(tnew);
for i=1:length(tnew)-1
    if  abs(tnew(i)-tnew(i+1) )<1e-12
        id(i)=0;
    end
    if  (tnew(i)<0) || (tnew(i)>1)
        id(i)=0;
    end
    if  (tnew(i+1)<0) || (tnew(i+1)>1)
        id(i+1)=0;
    end
    
    
    
end
id(find(id==0))=[];

tnew=tnew(id);



% % % % % % vep=min(diff(tnew))/2;
% % % % % % shuzhitidu=@(s)(pp(s+vep)-pp(s-vep)  );
% % % % % % for i=1:length(tnew)
% % % % % %     xnew(i)=xtau(tnew(i) );
% % % % % %     fuhao(i)=sign( imag( shuzhitidu(tnew(i)) ));
% % % % % % end

chaju = diff(tnew)/2;
for i=1
    vep=chaju(i)/3;
    shuzhitidu=@(s)(pp(s+vep)-0 );
    xnew(i)=xtau(tnew(i) );
    fuhao(i)=sign( imag( shuzhitidu(tnew(i)) ));
end
for i=length(tnew)
    vep=chaju(i-1)/3;
    shuzhitidu=@(s)(0-pp(s-vep)  );
    xnew(i)=xtau(tnew(i) );
    fuhao(i)=sign( imag( shuzhitidu(tnew(i)) ));
end
for i=2:(length(tnew)-1)
    vep=min([chaju(i),chaju(i-1)])/3;
    shuzhitidu=@(s)(   pp(s+vep)-pp(s-vep) );
    xnew(i)=xtau(tnew(i) );
    fuhao(i)=sign( imag( shuzhitidu(tnew(i)) ));
end
















W=0;
for i=1:length(xnew)
    if(xnew(i)>0)
    W=W+fuhao(i);
    end
end


% W
jiaodianshu=length(tnew)


% % % xnew
% % % tnew
% % % % % 
% % xnew
% % tnew
% % 
% % 
% % fuhao





% % % % % % %
% % % % % % %
% % % % % % %
% % % % % % % jieguo.zeropt=zeropt;
% % % % % % % for i=1:length(zeropt)
% % % % % % %     jieguo.x(i)= xtau( zeropt(i) )   ;
% % % % % % % end
% % % % % % %
% % % % % % %
% % % % % % % % % % % % % % % %
% % % % % % % [xnew,index] = sort([jieguo.x])
% % % % % % % snew=zeropt(index)
% % % % % % % id=1:length(snew);
% % % % % % % for i=1:length(xnew)-1
% % % % % % %     if  abs(xnew(i)-xnew(i+1) )<1e-10
% % % % % % %         id(i)=0;
% % % % % % %     end
% % % % % % %
% % % % % % % end
% % % % % % % id(find(id==0))=[];
% % % % % % % snew=snew(id);
% % % % % % % % xnew=xnew(id);

% % % % snew
% % % % xnew





% % % %
% % % % zeropt=sort(zeropt)
% % % % id=1:length(zeropt);
% % % % for i =1:length(zeropt)-1
% % % %
% % % %     if abs(zeropt(i)-zeropt(i+1))< 1e-8
% % % %         id(i)=0;
% % % %     end
% % % %
% % % % end
% % % % id(find(id==0))=[]
% % % % id
% % % %
% % % % zeropt=zeropt(id);



h=5e-4;
tt=0:h:1;
ggy=1:length(tt);
ggr=1:length(tt);
ggf=1:length(tt);


for i=1:length(tt)
    ggy(i)=ytau(tt(i));
    ggf(i)=pp(tt(i));
    ggr(i)=abs(ggf(i));
end


plot( 0:h:1,ggy )
hold on
plot( 0:h:1,ggr )
hold on
figure(2)

plot(xnew,zeros(1,length(xnew)),'o','linewidth',5)
hold on
plot( ggf )



min(abs(xnew))
max(abs(xnew))

end

