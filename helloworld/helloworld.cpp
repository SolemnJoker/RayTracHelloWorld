﻿#include "stdafx.h"
#include <stdlib.h>   // card > aek.ppm
#include <stdio.h>
#include <math.h>
#include <ppl.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
typedef int i;typedef float f;struct v{
f x,y,z;v operator+(v r){return v(x+r.x
,y+r.y,z+r.z);}v operator*(f r){return
v(x*r,y*r,z*r);}f operator%(v r){return
x*r.x+y*r.y+z*r.z;}v(){}v operator^(v r
){return v(y*r.z-z*r.y,z*r.x-x*r.z,x*r.
y-y*r.x);}v(f a,f b,f c){x=a;y=b;z=c;}v
operator!(){return*this*(1/sqrt(*this%*
this));}};__int64 G[]={162542509388423,
162818214890121,166941376678537,
163093080738441,267820774617703,
140823387701761,140823387701761,
140823387701761,0};f R(){
return(f)rand()/RAND_MAX;}i T(v o,v d,f
&t,v&n){t=1e9;i m=0;f p=-o.z/d.z;if(.01
<p)t=p,n=v(0,0,1),m=1;for(i k=50;k--;)
for(i j=9;j--;)if(G[j]&((__int64)1)<<k){v p=o+v(-2*k
,0,-j-4);f b=p%d,c=p%p-1,q=b*b-c;if(q>0
){f s=-b-sqrt(q);if(s<t&&s>.01)t=s,n=!(
p+d*t),m=2;}}return m;}v S(v o,v d){f t
;v n;i m=T(o,d,t,n);if(!m)return v(.7,
.6,1)*pow(1-d.z,4);v h=o+d*t,l=!(v(9+R(
),9+R(),16)+h*-1),r=d+n*(n%d*-2);f b=l%
n;if(b<0||T(h,l,t,n))b=0;f p=pow(l%r*(b
>0),99);if(m&1){h=h*.2;return((i)(ceil(
h.x)+ceil(h.y))&1?v(3,1,1):v(3,3,3))*(b
*.2+.1);}return v(p,p,p)+S(h,r)*.5;}i
main(){
    cv::Mat m(512,3072,CV_8UC3);
    uchar* pix = m.data;
    v g=!v
(10,-30,0),a=!(v(0,0,1)^g)*.002,b=!(g^a
)*.002,c=(a+b)*-256+g;
    int count = 0;
    //for(i y=512;y--;)
    Concurrency::parallel_for(0,512,[&](int y)
    {
for(i x=3072;x--;){v p(13,13,13);for(i r
=64;r--;){v t=a*(R()-.5)*99+b*(R()-.5)*
99;p=S(v(17,16,8)+t,!(t*-1+(a*(R()+x)+b
*(y+R())+c)*16))*3.5+p;}
//printf("%c%c%c" ,(i)p.x,(i)p.y,(i)p.z)
 i id =(511-y)*m.step[0]+(3072-x)*3;
 pix[id] = p.x;
 pix[id +1] = p.y;
 pix[id+2] = p.z;
    ;}
    printf("%d\n",count++);
    });
cv::imwrite("f:/test.jpg",m);
}

