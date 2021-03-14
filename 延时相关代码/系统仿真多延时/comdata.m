function [ data ] = comdata( f,tt,dim)

 
data=zeros(dim,length(tt));

for i=1:length(tt)
    data(:,i)=f(tt(i));
end

end

