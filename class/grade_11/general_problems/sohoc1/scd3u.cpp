// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "scd3u"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        for (int j = i * i; j < arr; j += i){
            prime[j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    ll l, r;
    cin >> l >> r;
    r = sqrt(r);
    ll tmp = sqrt(l);
    if (tmp * tmp == l) l = sqrt(l);
    else if (tmp * tmp < l) l = sqrt(l) + 1;
    int res = 0;
    for (ll i = l; i <= r; ++i){
        if (!prime[i]) res++;
    }
    cout << res;
    return 0;
}