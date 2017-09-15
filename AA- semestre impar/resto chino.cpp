#include <iostream>
#include <vector>

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

int inversa(int a, int b){
	int x=EuclidesExtendido(a,b)[1];
	if (x<0)return b+x;
	return x;
}

void congruenciaLinear(int a, int b, int mod){//de la forma ax = b (modulo mod)
	int aux=inversa(a,mod);
	aux=MOD(aux*b,mod);
	
	cout<<"la solucion de "<<a<<"x = "<<b<<" es: ";
	cout<<"x = "<<aux<<" mod ("<<mod<<")"<<endl;
	cout<<"nombrados son: "<< aux-(2*mod)<<","<<aux-(1*mod)<<","<<aux<<","<<aux+mod<<","<<aux+(2*mod)<<"... al infinito"<<endl;	
}


vector<int> restoChino(vector<int>a,vector<int>p,int tam){//ecuaciones de la forma
	vector<int> resultado,p_1,q;						//x=a(mod p)
	int x_0,p_;
	x_0=0;
	p_=p[0];//variable usada para almacenar la multiplicacion de los modulos
	for(int i=1;i<tam;i++){
		p_=p_*p[i];
	}
	for(int i=0;i<tam;i++){
		p_1.push_back(p_/p[i]);//variable usada para almacenar cada p_...
	}							//entre el respectivo modulo 
	
	for(int i=0;i<tam;i++){
		q.push_back(inversa(p_1[i],p[i]));//calculamos las inversas
	}
	
	for(int i=0;i<tam;i++){
		cout<<"("<<a[i]<<" * ";
		cout<<p_1[i]<<" * ";
		cout<<q[i];
		if (i!=tam-1)cout<<") + ";
		
		x_0=x_0+(a[i]*p_1[i]*q[i]);
		
	}cout<<")"<<endl;
	
	if (x_0>p_)
		x_0=MOD(x_0,p_);
	
	resultado.push_back(x_0);
	resultado.push_back(p_);
	return resultado;
}

int main()
{
	/*vector<int>numeros;
	numeros.push_back(int(2));
	numeros.push_back(int(3));
	numeros.push_back(int(2));
	
	vector<int>modulos;
	modulos.push_back(int(3));
	modulos.push_back(int(5));
	modulos.push_back(int(7));
	
	vector<int>resultado;
	resultado=restoChino(numeros,modulos,3);
	cout <<"El resultado es: " <<resultado[0]<<" modulo "<<resultado[1]<<endl;*/
	
	congruenciaLinear(3,4,7);
	return 0;
}
