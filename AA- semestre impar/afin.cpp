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

afin::afin(int clave_a_, int clave_b_){
	alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
	clave_a=clave_a_;
	clave_b=clave_b_;
}

void afin::generarClave(){
	srand (time(NULL));
	lave_a=rand() % 100+1 ;//1-101
	while(mcd(clave_a,alfabeto.size())!=1)
		clave_a=rand() % 10000;
	clave_b=rand() % 10000;
	cout<<"a: "<<clave_a<<endl;
	cout<<"b: "<<clave_b<<endl;
}

string afin::cifrar(string palabra){
	int pos;
	long long i;
	for(i=0; i<palabra.size();i++){
		pos=alfabeto.find(palabra[i])*clave_a;
		pos+=clave_b;
		
		if(pos>=alfabeto.size()){
			palabra[i]=alfabeto[MOD(pos,(int)alfabeto.size())];
		}
		palabra[i]=alfabeto[pos];
	}
	return palabra;
}

string afin::descifrar(string palabra){
	vector<int>inversa = inversa(clave_a,alfabeto.size());
	int pos;
	for(int i=0; i<palabra.size();i++){
		pos=(alfabeto.find(palabra[i])-clave_b);
		if(pos<0)
			MOD(pos,alfabeto.size());
		pos=pos*inversa[1];
		palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
	}
	return palabra;
}
