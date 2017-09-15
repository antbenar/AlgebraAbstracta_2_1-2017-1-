#ifndef MAT_H
#define MAT_H
#include <iostream>
#include<vector>
#include <NTL/ZZ.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace NTL;
typedef ZZ minum;
ZZ convertir_decimal(vector <bool> a, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(a[i]==1)
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = elementos + indice - 1; i > indice; i--)
        {
            int temp = vec[i];
            vec[i] = vec[i - 1];
            vec[i - 1] = temp;
        }
    }
}
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = indice; i < indice + elementos - 1; i++)
        {
            int temp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = temp;
        }
    }
}
ZZ ga(int bits_seed, int bits_num, int particiones, int vueltas)
{
    vector <bool> a;
    for(int i = 0; i < bits_num; i++)
    {
        a.push_back(0);
    }
    for(int i = 0; i < bits_seed; i++)
    {
        a[i] = rand()%2;
    }
    int s = 0;
    for(int i = bits_seed; i < bits_num; i++)
    {
        a[i] = a[s] ^ a[s+1];
        s++;
    }
    int elementos_pedazo = bits_num/particiones;
    int residuo_elementos = bits_num%particiones;
    int indice = 0;
    int cont_particiones = 0;
    while(cont_particiones < particiones - 1)
    {
        if(cont_particiones%2 == 0)
        {
            rotar_izquierda(a, indice, elementos_pedazo, vueltas);
        }
        else
            rotar_derecha(a, indice, elementos_pedazo, vueltas);
        indice += elementos_pedazo;
        cont_particiones++;
    }
    if(cont_particiones%2 == 0)
    {
        rotar_izquierda(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);
    }
    else
        rotar_derecha(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);

    ZZ num;
    num = convertir_decimal(a, bits_num);
    return num;
}

template<typename T>
T MOD(T a,T n){
    T q=a/n;
    T r=a-(q*n);
    if(r<0)
        r=n+r;
    return r;
}int euclides(int a, int b){
    if(b == 0)
        return a;
    else
        return euclides(b, mod(a,b));
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

template<typename T>
T exponenciacion(T base, T exponente, T mod)
{
	T resultado = T(1);
	while(exponente > 0)
	{
	    if(MOD(exponente,2)==1) //si exponente es impar...
		{
			resultado = resultado*base; //resultado * base
			if(resultado>mod)
                resultado=MOD(resultado,mod);
		}
		base = base*base; //base * base
		if(base>mod)
            base=MOD(base,mod);
		exponente = exponente/2; //exponente / 2
    }
	return resultado;
}z

template<typename T>
T exponenciacion(T base, T exponente, T mod)
{
	T resultado = T(1);
	while(exponente > 0)
	{
	    if((exponente & 1)==1) //si exponente es impar...
		{
			resultado = resultado*base; //resultado * base
			if(resultado>mod)
                resultado=MOD(resultado,mod);
		}
		base = base*base; //base * base
		if(base>mod)
            base=MOD(base,mod);
		exponente = exponente>>1; //exponente / 2
    }
	return resultado;
}

vector<ZZ> euclides_extendido(ZZ dividendo,ZZ divisor){
     vector <ZZ> cocientes;
     ZZ residuo,temp,x,y,x_1,y_1;
     x=1;y=0;
     x_1=0;y_1=1;

     residuo=MOD(dividendo,divisor);//calculamos el MCD
     while(residuo>0){
        cocientes.push_back(dividendo/divisor);
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
     }
     cocientes.push_back(dividendo/divisor);

     for(long long i=0;i<cocientes.size();i++){//cout<<"x: "<<x<<", y: " << y<<endl;
        temp=x-(cocientes[i]*x_1);
        x=x_1;x_1=temp;
        temp=y-(cocientes[i]*y_1);
        y=y_1;y_1=temp;
     }//cout<<"x: "<<x<<", y: " << y<< ", x1: " << x_1<<", y1: "<<y_1<<endl;
     if(x<0)
        x=divisor-x;
     vector<ZZ>a;
     a.push_back(divisor);
     a.push_back(x);
     a.push_back(y);
     return a;
}

vector<ZZ> restoChino(vector<ZZ>a,vector<ZZ>p,int tam){
    vector<ZZ> resultado,p_1,q;
    ZZ x_0,p_;
    x_0=0;
    p_=p[0];
    for(int i=1;i<tam;i++){
        p_=p_*p[i];
    }
    for(int i=0;i<tam;i++){
        p_1.push_back(p_/p[i]);//cout<<p_1[i]<<endl;
    }
    for(int i=0;i<tam;i++){
        if(p_1[i]>p[i])
            q.push_back(euclides_extendido(MOD(p_1[i],p[i]),p[i]));
        else q.push_back(euclides_extendido(p_1[i],p[i]));//cout<<q[i]<<endl;
    }
    for(int i=0;i<tam;i++){
        /*cout<<a[i]<<", ";
        cout<<p_1[i]<<", ";
        cout<<q[i]<<endl;*/
        x_0=x_0+(a[i]*p_1[i]*q[i]);
    }
    if (x_0>p_)
        x_0=MOD(x_0,p_);

    resultado.push_back(x_0);
    resultado.push_back(p_);
    return resultado;
}

int PHI_euler(int num){
    int factorPrimo=2, exp=0,resultado=1;/////////////////////////CALCULAMOS LOS FACTORES
    vector<int>exp_factores;
    while(factorPrimo<=num){
        if(MOD(num,factorPrimo)==0){
            num=num/factorPrimo;
            exp++;
        }
        else{
            factorPrimo++;
            exp_factores.push_back(exp);
            exp=0;
        }
    }
    exp_factores.push_back(exp);
    for(int i=0;i<exp_factores.size();i++)
        cout<<exp_factores[i]<<endl;

    for(int i=0;i<exp_factores.size();i++){//////////////////////////EMPEZAMOS A CALCULAR EL PHI DE EULER
        if(exp_factores[i]==0)//i[0]=2;i[1]=3... i[n]=n+2
            continue;
        if(exp_factores[i]==1){
            resultado*=i+1;
        }
        else {
            resultado*=(pow((i+2),exp_factores[i])- pow((i+2),exp_factores[i]-1));
        }
        cout<<"adfss"<<endl;
    }
    return resultado;
}

bool fermat(ZZ p){
    ZZ a;
    a=ZZ(3);
    while(true){
        a=ga(4,1024,2,3);
        if(mcd(p,a)==1){
            break;
        }
    }
    if(exponenciacion(a,p-1,p)==1)
        return 1;
    return 0;
}

#endif // MAT_H
