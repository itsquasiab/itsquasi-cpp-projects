// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll rev(ll n){
    ll t = 0;
    while (n){
        t = t * 10 + (n % 10);
        n /= 10;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    if (n == 0) cout << 0;
    else cout << rev(n);
    return 0;
}