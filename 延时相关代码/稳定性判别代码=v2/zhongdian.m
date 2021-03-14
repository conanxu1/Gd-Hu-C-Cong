function [ zd] = zhongdian ( jiaoz  )

zd=[];


jiaoz
for i=1: (length(jiaoz)-1 )

    
    zd=[zd,(jiaoz(i)+jiaoz(i+1))/2];


end

zd

hold on
plot(zd,zeros(1,length(zd)),'xm')


end

