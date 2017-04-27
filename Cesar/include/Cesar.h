#ifndef CESAR_H
#define CESAR_H
#include<string>
using namespace std;

class Cesar
{
private:
    int clave;
public:
    string alfabeto;
    Cesar(int);
    string cifrar(string);
    string descifrar(string);
};

#endif // CESAR_H
