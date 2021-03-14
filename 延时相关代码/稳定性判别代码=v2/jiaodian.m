function [ jiaoz ] = jiaodian( pz )

jiaoz=[];

other=[];

if norm(pz(1))<1e-10
    jiaoz=[jiaoz,pz(1)];
end


for i =2:length(pz)
    if imag(pz(i))*imag(pz(i-1))<0
        x1= real(pz(i-1));
        x2= real(pz(i));
        y1= imag(pz(i-1));
        y2= imag(pz(i));
        
        jiaoz=[jiaoz, x1-(x2-x1)/(y2-y1)*y1   ];
% % % % % %        other=[other,pz(i-1),pz(i)];
        
    end
    
    
end



%去除相近交点
jiaon=sort(jiaoz)
id=1:length(jiaon);
for i =1:length(jiaon)-1

    if abs(jiaon(i)-jiaon(i+1))<max(abs(jiaon))*1e-4
        id(i)=0;
    end
        
end
id(find(id==0))=[]
jiaoz=jiaon(id);

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
plot(0,0,'or','linewidth',5)
hold on
plot(pz(1),'xr','linewidth',5)
hold on
plot(pz(end),'xr','linewidth',5)
hold on
plot(pz,'xg')
hold on
plot(jiaoz.',0*(1:length(jiaoz)) ,'mo')
hold on
plot(other ,'mo','linewidth',5)

% % other

end

