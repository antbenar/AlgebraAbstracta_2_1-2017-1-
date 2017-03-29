#include <iostream>
#include<vector>
using namespace std;

int MOD(int a,int n){
    int q=a/n;
    int r=a-(q*n);
    if(r<0)
        r=n+r;
    return r;
}

vector <int>EuclidesExtendido(int dividendo,int divisor){
     vector <int> cocientes;
     int residuo,temp,
     x=1,y=0,
     x_1=0,y_1=1;
     residuo=MOD(dividendo,divisor);
     while(residuo>0){
        cocientes.push_back(dividendo/divisor);
        residuo=MOD(dividendo,divisor);
        dividendo=divisor;
        divisor=residuo;
     }
     for(int i=0;i<cocientes.size();i++){
        temp=x-(cocientes[i]*x_1);
        x=x_1;x_1=temp;
        temp=y-(cocientes[i]*y_1);
        y=y_1;y_1=temp;
     }
     vector<int>a;
     a.push_back(x);
     a.push_back(y);
     return a;
}

int main()
{
    int dividendo=672,divisor=38,x,y;
    vector<int>a;
    a=EuclidesExtendido(dividendo,divisor);
    cout<<"x: "<<a[0]<<" y: "<<a[1];
}
