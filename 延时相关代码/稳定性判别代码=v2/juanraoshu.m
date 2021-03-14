function [ W ] = juanraoshu( point,pz)



Argpz=angle(pz-point);
Num=0;
for t=2:length(Argpz)
    if abs(Argpz(t)-Argpz(t-1))>1
        if (Argpz(t)-Argpz(t-1))>0
            Num=Num-1;
            Argpz(t:end)=Argpz(t:end)-2*pi;
        else
            Num=Num+1;
            Argpz(t:end)=Argpz(t:end)+2*pi;
        end
    end
end


 
W=  round(   abs(Argpz(length(Argpz))-Argpz(1))/(2*pi)  );



 
 


end

