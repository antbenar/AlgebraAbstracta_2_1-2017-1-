#include "afin.h"
#include<string>
#include "euclides.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

afin::afin(){
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    generarClave();
}

afin::afin(ZZ clave_a_, ZZ clave_b_){
    alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    clave_a=clave_a_;
    clave_b=clave_b_;
}

void afin::generarClave(){
    srand (time(NULL));
    this->clave_a=rand() % 100+1 ;//1-101
    while(mcd(this->clave_a,(ZZ)alfabeto.size())!=1)
        clave_a=rand() % 1000000000+1 ;//1-101
    clave_b=rand() % 1000000000+1 ;//1-100
    cout<<"a: "<<clave_a<<endl;cout<<"b: "<<clave_b<<endl;
}

string afin::cifrar(string palabra){
    ZZ pos;
    long long i;
    for(i=0; i<palabra.size();i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        pos=alfabeto.find(palabra[i])*clave_a;
        if(pos>=alfabeto.size())
            pos=MOD(pos,(ZZ)alfabeto.size());
        pos+=clave_b;//cout<<"pos: " <<pos<<endl;
        if(pos>=alfabeto.size()){
            palabra[i]=alfabeto[MOD(pos,(ZZ)alfabeto.size())];//cout<<"MOD: "<<MOD(pos,alfabeto.size())<<endl;
        }
        palabra[i]=alfabeto[pos];
    }
    return palabra;
}

string afin::descifrar(string palabra){
    vector<ZZ>result_euclides=euclides_extendido(clave_a,alfabeto.size());//cout<<"inversa: "<< result_euclides[1];
    ZZ pos;
    for(ZZ i=0; i<palabra.size();i++){
        pos=(alfabeto.find(palabra[i])-clave_b);
        if(pos<0)
            MOD(pos,alfabeto.size());
        pos=pos*result_euclides[1];
        palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
    }
    return palabra;
}
