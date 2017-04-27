#include <iostream>
#include "rutas.h"
#include <string>
using namespace std;

int main()
{
    Rutas ruta(4);//3,7,6,11,12,13,...
    string b,a;
    cout<< "escriba su frase a cifrar: ";
    getline(cin,b);
    a=ruta.cifrar(b);
    cout<< "su clave cifrada es: "<<a<<endl;
    cout<< "su clave descifrada es: "<<ruta.descifrar(a)<<endl;
    return 0;
}
