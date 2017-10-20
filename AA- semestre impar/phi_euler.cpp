#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int MOD(int a,int n){
	int q=a/n;
	int r=a-(q*n);
	if(r<0)
		r=n+r;
	return r;
}

vector<int> criba(int n)
{
	vector<int> s;
	bool es_primo;
	long long pos=0;
	
	s.push_back(2);
	for(int j = 3;j<n;j+=2)
	{
		es_primo = true;
		for(long long i=0;i<sqrt(pos);i++)
		{
			if (MOD(j,s[i]) == 0)
			{
				es_primo= false;
				break;
			}
		}
		if(es_primo == true)
		{
			s.push_back(j);
			pos++;
		}
	}
	return s;
}

int phi_euler(int num){	
	vector<int>criba_=criba(sqrt(num));
	int num_=num;

	int resultado=1;/////////////////////////CALCULAMOS LOS FACTORES
	int exp=0;
	int i=0;
	cout<<"phi_euler de "<<num<<" es: "<<endl;
	while(num>1){
		while(num>0 && MOD(num,criba_[i])==0){
			num=num/criba_[i];
			exp++;
		}
		if(exp>0){
			resultado = resultado * (pow(criba_[i],exp)-pow(criba_[i],exp-1));
			cout<<" ("<< criba_[i] << "^" << exp << " - " << criba_[i] << "^" << exp-1 <<")";
		}
		i++;
		exp=0;
	}
	
	cout<<" = "<<resultado<<endl;
	return resultado;
}


int main()
{
	//int n;
	//cout<<"ingrese el numero a hallar su phi de Euler: "; cin>>n;
	
	phi_euler(240);
	
	return 0;
}
