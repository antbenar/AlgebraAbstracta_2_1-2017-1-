#ifndef AFIN_H
#define AFIN_H
#include<string>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
class afin
{
private:
    ZZ clave_a;
    ZZ clave_b;
    void generarClave();
public:
    string alfabeto;
    afin();
    afin(ZZ,ZZ);
    string cifrar(string);
    string descifrar(string);
};

#endif // AFIN_H
