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

/*int euclides(int a, int b)
{
     int residuo = modulo(a,b);
     while(residuo!=0)
     {
         a = b;
         b = residuo;
         residuo = modulo(a,b);
     }
     return b;
}

vector <int>EuclidesExtendido(int dividendo,int divisor){
     vector <int> cocientes;
     int residuo,temp,
     x=1,y=0,
     x_1=0,y_1=1;
     residuo=MOD(dividendo,divisor);
     while(residuo>0){
        cocientes.push_back(dividendo/divisor);
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
     }
     cocientes.push_back(dividendo/divisor);

     for(int i=0;i<cocientes.size();i++){//cout<<"x: "<<x<<", y: " << y<<endl;
        temp=x-(cocientes[i]*x_1);
        x=x_1;x_1=temp;
        temp=y-(cocientes[i]*y_1);
        y=y_1;y_1=temp;
     }//cout<<"x: "<<x<<", y: " << y<< ", x1: " << x_1<<", y1: "<<y_1<<endl;
     vector<int>a;
     a.push_back(divisor);
     a.push_back(x);
     a.push_back(y);
     return a;
}

int main()
{
    int dividendo=161,divisor=24,x,y;
    vector<int>a;
    a=EuclidesExtendido(dividendo,divisor);
    cout<<"mcd: "<<a[0]<<" x: "<<a[1]<<" y: "<<a[2];
}*/

int euclides(int a, int b){
	int residuo=MOD(a,b);
	cout<<a<<" = " << b << "*" << a/b << " + " << residuo<<endl;
	while(residuo>0){
		a=b;
		b=residuo;
		residuo=MOD(a,b);
		cout<<a<<" = " << b << "*" << a/b << " + " << residuo<<endl;
	}
	return b;
}

int main()
{
	while(1){
		int a,b;
		cout<<"ingrese a: ";
		cin>>a;
		cout<<"ingrese b: ";
		cin>>b;
		cout << euclides(a,b) << endl << endl;
	}

	return 0;
}
