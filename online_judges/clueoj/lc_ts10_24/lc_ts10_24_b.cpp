// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "lc_ts10_24_b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
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
    ll a, b;
    cin >> a >> b;
    ll a1 = sqrt(a), b1 = sqrt(b);
    if (a1 * a1 != a) a1++;
    ll res = 0;
    for (int i = a1; i <= b1; ++i){
        if (!prime[i]) res++;
    }
    cout << res;
    return 0;
}
