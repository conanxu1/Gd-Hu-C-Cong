function [pz]=Pzf( snow,Ai,taui,n  )


[dimxm,dimxn]=size(Ai{1,1});
    tp=snow*eye(dimxm);
    tp=tp-Ai{n+1,1};
    for j=1:n
        tp=tp- Ai{j,1}*exp(-snow *taui(j)  );
    end
    pz=det(tp);
end

