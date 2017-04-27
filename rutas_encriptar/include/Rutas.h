#ifndef RUTAS_H
#define RUTAS_H
#include<string>

using namespace std;

class Rutas
{
private:
    int clave;
public:
    string alfabeto;
    Rutas(int);
    string cifrar(string);
    string descifrar(string);
};

#endif // RUTAS_H
