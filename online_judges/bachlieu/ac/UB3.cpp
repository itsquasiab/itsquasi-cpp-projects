// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

ll sumdivs(ll n){
    ll res = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            res *= (fastpow(i, e + 1) - 1) / (i - 1);
        }
    }
    if (n > 1) res *= (fastpow(n, 2) - 1) / (n - 1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    cout << sumdivs(n);
    return 0;
}