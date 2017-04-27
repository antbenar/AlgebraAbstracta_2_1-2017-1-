#ifndef RSA_H
#define RSA_H
using namespace NTL;
typedef ZZ minum;

class RSA
{
private:
    minum clave_a;
    minum clave_b;
    void generarClave();
public:
    string alfabeto;
    RSA();
    RSA(minum,minum);
    string cifrar(string);
    string descifrar(string);
};

#endif // RSA_H
