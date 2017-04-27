#ifndef MATEMATIC_H
#define MATEMATIC_H

int MOD(int a,int n){
    int q=a/n;
    int r=a-(q*n);
    if(r<0)
        r=n+r;
    return r;
}
#endif // MATEMATIC_H
