#include<bits/stdc++.h>
using namespace std;

//Futher reading: https://cp-algorithms.com/algebra/binary-exp.html


#define MOD 1000000007

//Modular Arithmetic property:
//(m * n) % p =((m % p) * (n % p)) % p

long long int powerModulo(int a, int b){
    if (b == 0)
        return 1;
    long long int res = powerModulo(a, b/2);
    
    if (b & 1)
        return res * res * a % MOD;
    else
        return res * res % MOD;
}

int main(){
    cout << powerModulo(5, 3) << endl;
    return 0;
}