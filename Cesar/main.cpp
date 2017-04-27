#include <iostream>
#include<Cesar.h>
#include<string>

using namespace std;

int main()
{
    Cesar Cesar_(3);
    string b,a;
    cout<< "escriba su frase a descifrar: ";
    getline(cin,b);
    //a=Cesar_.cifrar(b);
    //cout<< "su clave cifrada es: "<<a<<endl;
    cout<< "su clave descifrada es: "<<Cesar_.descifrar(b)<<endl;
    return 0;
}
