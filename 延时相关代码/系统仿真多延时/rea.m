function dydt =rea(t,y,Z)
global N
global dimx

global gAi
global gBi
global gtaui

 

 
dydt =gAi{N+1,1}*y+gBi{N+1,1}*myut(t);

for k=1:N
    dydt=dydt+ gAi{k}*Z(:,k)+ gBi{k}*  myut(t-gtaui(k));
end


end