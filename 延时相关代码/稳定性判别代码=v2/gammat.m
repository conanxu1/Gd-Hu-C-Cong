function [ snow ] = gammat( taunow,bbeta )

taunow=taunow-floor(taunow);


if taunow<0.5;
    
    snow=bbeta*cos( (taunow-1/4)*2*pi ) +1i*bbeta*sin( (taunow-1/4)*2*pi) ;
else
    snow=	 0+1i*  (bbeta-  2*bbeta*   (taunow-1/2)*2 );
end
end

