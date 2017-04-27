#include <iostream>
#include <RSA.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
typedef ZZ minum;

int main()
{
    RSA RSA_;
    string b,a;
    cout<< "escriba su frase a cifrar: ";
    getline(cin,b);
    a=RSA.cifrar();

    RSA RSA_
    cout<< "su clave cifrada es: "<<a<<endl;
    return 0;
}
