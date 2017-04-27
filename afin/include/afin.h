#ifndef AFIN_H
#define AFIN_H
#include<string>
using namespace std;

class afin
{
private:
    int clave_a;
    int clave_b;
    void generarClave();
public:
    string alfabeto;
    afin();
    string cifrar(string);
    string descifrar(string,int,int);
};

#endif // AFIN_H
