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

void afin::generarClave(){
    srand (time(NULL));
    clave_a=rand() % 100+1 ;//1-101
    while(mcd(clave_a,alfabeto.size())!=1)
        clave_a=rand() % 100+1 ;//1-101
    clave_b=rand() % 100+1 ;//1-100
    cout<<"a: "<<clave_a<<endl;cout<<"b: "<<clave_b<<endl;
}

string afin::cifrar(string palabra){
    int pos;
    for(int i=0; i<palabra.size();i++){//cout<<"alfabeto letra: " <<alfabeto.find(palabra[i]);
        pos=alfabeto.find(palabra[i])*clave_a;
        if(pos>=alfabeto.size())
            pos=MOD(pos,alfabeto.size());
        pos+=clave_b;//cout<<"pos: " <<pos<<endl;
        if(pos>=alfabeto.size()){
            palabra[i]=alfabeto[MOD(pos,alfabeto.size())];//cout<<"MOD: "<<MOD(pos,alfabeto.size())<<endl;
        }
        palabra[i]=alfabeto[pos];
    }
    return palabra;
}

string afin::descifrar(string palabra,int clave_a_,int clave_b_){
    clave_a=clave_a_;
    clave_b=clave_b_;
    vector<int>result_euclides=euclides_extendido(clave_a,alfabeto.size());//cout<<"inversa: "<< result_euclides[1];
    int pos;
    for(int i=0; i<palabra.size();i++){
        pos=(alfabeto.find(palabra[i])-clave_b);
        if(pos<0)
            MOD(pos,alfabeto.size());
        pos=pos*result_euclides[1];
        palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
    }
    return palabra;
}
