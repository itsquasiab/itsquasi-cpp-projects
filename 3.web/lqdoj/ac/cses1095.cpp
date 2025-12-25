//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll fastpow(ll x, ll y){
    if (y == 0) return 1;
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll a, b;
        cin >> a >> b;
        cout << fastpow(a, b) << "\n";
    }
    return 0;
}