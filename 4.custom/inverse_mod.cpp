//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll very_fast(int a, int n){
    if (n == 0) return 1;
    ll tmp = very_fast(a, n / 2);
    tmp = (tmp * tmp) % mod;
    if (n % 2 == 1) tmp = (tmp * a) % mod;
    return tmp;
}

ll inverse_mod(int a){
    return very_fast(a, mod - 2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    return 0;
}