#include "Cesar.h"
#include<string>
#include "matematic.h"
using namespace std;

Cesar::Cesar(int clave_){
	alfabeto="abcdefghijklmnopqrstuvwxyz ";
	clave=clave_;
}

string Cesar::cifrar(string palabra){
	int pos;
	for(int i=0; i<palabra.size();i++){
		pos=alfabeto.find(palabra[i])+clave;
		palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
	}
	return palabra;
}
string Cesar::descifrar(string palabra){
	int pos;
	for(int i=0; i<palabra.size();i++){
		pos=alfabeto.find(palabra[i])-clave;
		palabra[i]=alfabeto[MOD(pos,alfabeto.size())];
	}
	return palabra;
}
