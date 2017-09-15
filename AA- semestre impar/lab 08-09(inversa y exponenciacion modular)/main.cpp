#include <iostream>
#include <vector>
using namespace std;

int mod(int a,int n){
    int q=a/n;
    int r=a-(q*n);
    if(r<0)
        r=n+r;
    return r;
}

int euclides(int a, int b){
	int residuo=mod(a,b);
	while(residuo>0){
		a=b;
		b=residuo;
		residuo=mod(a,b);
	}
	return b;
}

int multMod(int a,int n, int modulo){
    //cout<<"multMod ("<<a<<","<<n<<")"<<endl;
    a=mod(a,modulo);//cout<<a<<" = mod("<<a<<","<<modulo<<")"<<endl;
    n=mod(n,modulo);//cout<<n<<" = mod("<<n<<","<<modulo<<")"<<endl;
    return mod(a*n,modulo);
}

int inversaMod(int a, int modulo){
    int cont=0;
    int aux;
    a=mod(a,modulo);

    if(euclides(a,modulo)!=1)return 0;

    aux=multMod(a,cont,modulo);                 cout<<endl;
    while(aux!=1){
        cout << a<<" * "<<cont<<" = "<<aux << " (mod "<<modulo<<")"<< endl<<endl;
        cont++;
        aux=multMod(a,cont,modulo);
    }
    return cont;
}

vector<int>convAdecimal(int numero){
    int num= numero;
    vector <int> resultado(7,0);
    int i=6;

    while(numero>0){
        resultado[i]=mod(numero,2);
        numero=numero/2;
        i--;
    }

    ///////////////////////ESTE SEGMENTO ES PARA IMPRIMIR////////////////////////
    cout<<"el numero "<< num << " en binario es: ";
    for(int i=0;i<7;i++){
        cout<<resultado[i];
    }cout<<endl<<endl;
    return resultado;
}

int exponenciacionMOD(int base,int exponente_, int modulo)
{
    int base_=base;
    vector<int>exponente=convAdecimal(exponente_);
	int resultado = 1;
	int i=exponente.size()-1;

	while(i >= 0)
	{
	    if(exponente[i]==1) //si exponente es impar...
		{
			resultado = resultado*base; //resultado * base
			if(resultado>modulo)
                resultado=mod(resultado,modulo);

            cout<<base_<<"^(2^"<<6-i<<") mod("<<modulo<<") = "<<base<<endl;
		}
		else{
            cout<<base_<<"^(2^"<<6-i<<") mod("<<modulo<<") SE OMITE"<<endl;
		}
		base = base*base; //base * base
		if(base>modulo)
            base=mod(base,modulo);
        i--;
    }
	return resultado;
}

int main()
{
    //cout << multMod(4,-3,5) << endl;
    //cout << "la inversa modular de 88 modulo 13 es: "<<inversaMod(88,13) << endl;
    //convAdecimal(117);
    cout<< "5 ^ 117 modulo 19 ="<<exponenciacionMOD(5,117, 19)<<endl;
    return 0;
}
