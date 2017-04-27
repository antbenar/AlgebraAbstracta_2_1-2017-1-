#include "Rutas.h"
#include<string>
#include <iostream>
using namespace std;

Rutas::Rutas(int clave_)
{
    alfabeto="abcdefghijklmnopqrstuvwxyz";
    clave=clave_;
}
string Rutas::cifrar(string palabra){
    string cifrado;//string resultado
    int avance,pos;

    while((palabra.size()-clave) % (clave-1) !=0 || palabra.size()<clave)//porque no es modulo exacto de la clave para saber hasta donde rellenar de "*"
        palabra+="*";

    for( int i=0; i<clave; i++){
        pos=avance=(2*(clave-i)) -3;//lo que avanza entre caracter y caracter
        cifrado+=palabra[0];
        palabra.erase(0,1);//cout<<"for "<<i<<": "<<palabra<<", cifrado: "<<cifrado<<endl;
        while(pos < palabra.size()){
            if(i==0){
                cifrado+=palabra[pos];
                palabra.erase(pos,1); //cout<<"while if_1 "<<pos<<": "<<palabra<<", cifrado: "<<cifrado<<endl;
            }
            else if(pos>0){
                cifrado+=palabra[pos];
                palabra.erase(pos,1);//cout<<"while if_2 "<<pos<<": "<<palabra<<", cifrado: "<<cifrado<<endl;
                if(pos< palabra.size()){
                    cifrado+=palabra[pos];
                    palabra.erase(pos,1);//cout<<"while if_3 "<<pos<<": "<<palabra<<", cifrado: "<<cifrado<<endl;
                }
            }
            pos+=avance;
        }
    }
    while(palabra.size()>0){
        cifrado+=palabra[0];
        palabra.erase(0,1);//cout<<"while if_4: "<<palabra<<", cifrado: "<<cifrado<<endl;
    }
    return cifrado;
}

string Rutas::descifrar(string palabra){
    string descifrado,//string resultado
    aux;// string auxiliar
    int pos,//posicion para recorrer el string
    temp,//usado para enteros temporales
    num_centrales,//numero de caracteres por fila central
    arriba,//numero para saber cuantos digitos lleva arriba
    abajo;//numero para saber cuantos digitos lleva abajo
    bool val;

    num_centrales=palabra.size()/(clave-1);
    temp=palabra.size()-((clave-2 )*num_centrales);//numero total de caracteres ubicdos en las filas centrales
    if(temp%2==0)//calculamos si hay mas filas arriba o abajo
        arriba=abajo=temp/2;
    else{
        arriba=(temp/2)+1;
        abajo=temp-arriba;
    }
           /* cout<<"arriba "<<arriba<<endl;
            cout<<"abajo "<<abajo<<endl;
            cout<<"num_centrales "<<num_centrales<<endl;*/

    while(abajo>0){
        aux.insert(0,1,palabra[palabra.size()-1]);//cout<<"while if_1: "<<aux<<endl;
        palabra.erase(palabra.size()-1,1);
        pos=palabra.size()-abajo;
        if(abajo==arriba){
            val=true;
            while(pos>=arriba){
                aux.insert(0,1,palabra[pos]);//cout<<"while if_2: "<<aux<<endl;
                palabra.erase(pos,1);
                pos-=num_centrales;
            }
        }
        else{
            if (val)
                num_centrales-=2;
            else
                num_centrales-=1;//cout<<"num_centrales               "<<num_centrales<<" pos:"<< pos<<endl;
            while(pos>=arriba){
                aux+=palabra[pos];//cout<<"while if_3: "<<aux<<endl;
                palabra.erase(pos,1);
                pos--;
                aux.insert(0,1,palabra[pos]);//cout<<"while if_4: "<<aux<<endl;
                palabra.erase(pos,1);
                pos-=num_centrales;
            }
            if(!val)
                num_centrales-=1;
        }
        descifrado.insert(0,aux);
        aux="";
        abajo--;
    }

    for(int i=0;i<arriba;i++){
        descifrado.insert(((clave)*2-2)*i,1,palabra[i]);
    }
    int i=1;
    while(i>0){//le quitamos los "*"
        if(descifrado[descifrado.size()-i]=='*'){
            i++;
        }
        else break;
    }
    descifrado.erase(descifrado.size()-i+1,i-1);

    return descifrado;
}
