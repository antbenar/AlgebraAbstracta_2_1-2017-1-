#include <iostream>
#include<vector>
#include <NTL/ZZ.h>

using namespace std:
using namespace NTL;
typedef ZZ minum;

minum MOD(minum a,minum n){
    minum q=a/n;
    minum r=a-(q*n);
    if(r<0)
        r=n+r;
    return r;
}

minum mcd(minum a,minum b){
    minum c=MOD(a,b);
    while(c>0){
        a=b;
        b=c;
        c=MOD(a,b);
    }
    return b;
}

vector <minum>euclides_extendido(minum dividendo,minum divisor){
     vector <minum> cocientes;
     minum residuo,temp,
     x=1,y=0,
     x_1=0,y_1=1;

     residuo=MOD(dividendo,divisor);//calculamos el MCD
     while(residuo>0){
        cocientes.push_back(dividendo/divisor);
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
     }
     cocientes.push_back(dividendo/divisor);

     for(minum i=0;i<cocientes.size();i++){//cout<<"x: "<<x<<", y: " << y<<endl;
        temp=x-(cocientes[i]*x_1);
        x=x_1;x_1=temp;
        temp=y-(cocientes[i]*y_1);
        y=y_1;y_1=temp;
     }//cout<<"x: "<<x<<", y: " << y<< ", x1: " << x_1<<", y1: "<<y_1<<endl;
     vector<minum>a;
     a.push_back(divisor);
     a.push_back(x);
     a.push_back(y);
     return a;
}
/*
int main()
{
    minum dividendo=161,divisor=24,x,y;
    vector<minum>a;
    a=EuclidesExtendido(dividendo,divisor);
    cout<<"mcd: "<<a[0]<<" x: "<<a[1]<<" y: "<<a[2];
}

*/
