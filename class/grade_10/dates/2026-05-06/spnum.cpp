// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "spnum"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[0] = prime[1] = 1;
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
    ll n;
    cin >> n;
    n = sqrt(n);
    ll t = 0;
    for (int i = 1; i <= n; ++i){
        if (!prime[i]) t++;
    }
    cout << t;
    return 0;
}