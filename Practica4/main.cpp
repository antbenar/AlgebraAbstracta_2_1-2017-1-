#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <math.h>
#include <vector>
#include "mat.h"
using namespace std;
using namespace NTL;

int mod(int a,int b){
    int q,r;
	q = a/b;
	r = a - (q*b);
	if (r<0)
		r=r+b;
	return r;
}

/////////////////////////////////////////////////////////////// 1
void random(int seed,int a, int b, int n){
    int aux;
    int x = seed;
    aux = (a*x) + b;
    x = mod(aux,n);
    cout<<x<<endl;
    while(x!= seed){
        aux = (a*x) + b;
        x = mod(aux,n);
        cout<<x<<endl;
        }
}

//////////////////////////////////////////////////////////////// 2
int euclides(int a, int b){
    if(b == 0)
        return a;
    return euclides(b, mod(a,b));
}
//El  algoritmo iterativo es mas efciente porque hacen lo mismo pero con
//la diferencia de que el otro no gasta tiempo computacional al hacer llamada tras llamada a la funcion



//////////////////////////////////////////////////////////////////// 3
vector<int> mcd(int a, int b){
    int u=1,g=a,x=0,y=b,r,s,q,v;
    while (y!=0){
        r = mod(g,y);
        q = g/y;
        s = u-q*x;
        u=x;g=y;
        x=s;y=r;
    }
    if(b==0){
        g=a;u=1,v=0;
    }
    else
        v=(g-a*u)/b;
    if(u<0)u=u+b;
    vector<int> resultado;
    resultado.push_back(g);
    resultado.push_back(u);
    resultado.push_back(v);
    return resultado;
}
//c) Si b==0 habria una division entre 0 y como esta es indeterminada, el programa no procederia


/////////////////////////////////////////////////////////////////////// 4
int abs(int x){
    if(x<0)return -1*x;
    return x;
}

int xx(int a,int b)
{
    if(a==0)
        return b;
    else if (b==0)
        return a;
    else if ((mod(a,2) == 0) and (mod(b,2)==0))
        return 2 * xx(a/2,b/2);
    else if ((mod(a,2) == 0) and (mod(b,2)==1))
        return xx(a/2,b);
    else if ((mod(a,2) == 1) and (mod(b,2)==0))
        return xx(a,b/2);
    else
        return xx(abs(a-b)/2,a);
}
//Lo que hace este algoritmo es calcular el mcd de dos numeros pero su algoritmo es muy ineficiennte
// ya que en cada iteracion lo trata de rec=ducr dividiendolo de 2 en 2



////////////////////////////////////////////////////////////////////////// 5
int gcd(int a, int b){
    if(a<b){
        int temp=a;
        a=b;
        b=temp;
    }
    int g=1,t;
    while(mod(a,2)==0 and mod(b,2)==0){
        a/=2; b/=2; g*=2;
    }
    while(a!=0){//cout<<a<<b<<endl;
        while(mod(a,2)==0)
            a/=2;
        while(mod(b,2)==0)
            b/=2;
        t=abs(a-b)/2;
        if(a>=b)
            a=t;
    }
    return g*b;
}

////////////////////////////////////////////////////////////////////////// 6
int exponenciacion_1(int a,int p, int n)
{
    int r = 1;
    for(int i=0;i<p;i++)
    {
        r = mod(r*a,n);
    }
    return r;
}


////////////////////////////////////////////////////////////////////////// 7
int exponenciacion_2(int a,int p,int n)
{
    int r;
    if(p == 0)
    {
        return 1;
    }
    if(mod(p,2)==0)
    {
        r = exponenciacion_2(a,p/2,n);
        r = r*r;
        return mod(r,n);
    }
    r =exponenciacion_2(a,(p-1)/2,n);
    return mod(a*mod(r*r,n),n);
}
//El que converge mas rapido es este algoritmo puesto que solo multiplica un numero limitado de veces, siempre menos que p
//para asi tratar de hacer la menos cantidad de operaciones posibles



///////////////////////////////////////////////////////////////////////////////8
int ejercicio8(int N,int g,int A)
{
    int a = g;
    int b = 1;
    while(A > 0)
    {
        if(mod(A,2) == 1)
           {
               b = mod((b*a),N);
           }
        a = exponenciacion_1(a,2,N);
        A = A/2;
    }
    return b;
}

//////////////////////////////////////////////////////////////////////////////////9
vector<int> ejercicio9(int a,int b)
{
    vector<int> res(3,0);
    vector<int> t(3,0);
    if(b == 0)
    {
        res[0] = a;
        res[1] = 1;
        res[2] = 0;
        return res;
    }
    int q = mod(a,b);
    int r = (a-q)/b;
    t = ejercicio9(b,q);
    res[0] = t[0];
    res[1] = t[2];
    res[2] = t[2]-t[1]*r;
    return res;
}
//Lo que hace este codigo es calcular el maximo comun divisor asi como su x y su y



/////////////////////////////////////////////////////////////////////////////////////////10
/*vector<int> primos(int n)
{
    vector<int> s;
    bool es_primo;
    int pos=0;
    for(int j = 2;j<n;j++)
    {
        es_primo = true;
        for(int i=0;i<pos;i++)
        {
            if (mod(j,s[i]) == 0)
            {
                es_primo= false;
                break;
            }
        }
        if(es_primo == true)
        {
            s.push_back(j);//cout<<s[pos]<<endl;
            pos++;
        }
    }
    return s;
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////  11
vector<int> criba_Eratostenes(int n){
    vector<int>lista(n-1,1);
    int j=0,k=0,pivote;//j[0]=2,j[1]=3,...

    while(j<n-2){
        while(lista[j]==0){//0 es falso
            j++;
        }
        pivote=j+2;
        k=j+3;j++;
        while(k<n){
            if(lista[k]==1&&mod(k,pivote)==0){
                lista[k]=0;//cout<<k<<endl;
            }
            k++;
        }
    }
    return lista;
}


//////////////////////////////////////////////////////////////////////////////////////////////////// 12
bool primTest(ZZ p){
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

//////////////////////////////////////////////////////////////////////////////////////////////////////// 13
int inverse(int a, int n){
    vector<int>res(3,0);
    res=mcd(a,n);
    if(res[0]==1)return res[1];
    cout<< "No inverse";
    return -1;
}

int main()
{
//    random(0,3,7,11);//////// 1

//    cout<<euclides(412,260)<<endl;////// 2

//    vector<int>resultado;////////////////// 3
//    resultado=mcd(527,1258);
////    resultado=mcd(228,1056);
////    resultado=mcd(163961,167181);
////    resultado=mcd(3892394,239847);
//    cout<<resultado[0]<<endl;
//    cout<<resultado[1]<<endl;
//    cout<<resultado[2]<<endl;

//    cout<<xx(1764,868)<<endl;/////////////////4

//    cout<<gcd(85,75);//////////////////////////////5///////////////////

//    cout<<exponenciacion_1(30192,43791,65301)<<endl;///////6
//    cout<<exponenciacion_2(30192,43791,65301);//////////////////7

//    cout<<ejercicio8(4,2,5);///////////////////////////////////////8

//    vector<int> res(3,0);////////////////////////////////////////////////9
//    res = ejercicio9(2093,836);
//    for(int i = 0;i<3;i++)cout<<res[i]<<endl;

//    vector<int>s;//////////////////////////////////////////////////////////////10
//    s=primos(10);
//    for(int i=0;i<s.size();i++){
//        cout<<s[i]<<endl;
//    }

//    vector<int> a=criba_Eratostenes(50);////////////////////////////////////////////11
//    for(int i=0;i<a.size();i++){
//        if(a[i]==1)
//            cout<<i+2<<endl;
//    }

//    cout<<primTest(ZZ(7));///////////////////////////////////////////////////////////////////12

//    cout<<inverse(3,8);/////////////////////////////////////////////////////////////////////////13

    cout<<PHI_euler(35);
    return 0;
}
