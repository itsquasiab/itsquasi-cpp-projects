//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    cout << fastpow(2, n);
    return 0;
}