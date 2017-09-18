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


int main()
{
    vector<int> a=criba(1000000);
    long long i;
    for(i=0;i<a.size()-1;i++)
    {
    cout << a[i] << endl;
    }cout<<a[i]<<endl;
    return 0;
}
