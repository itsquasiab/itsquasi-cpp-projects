// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
ll pf[arr];

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
    int n, t;
    cin >> n >> t;
    ll p, q, m;
    cin >> p >> q >> m;
    for (int i = 1; i <= n; ++i){
        a[i] = (p * i) % m + q;
        pf[i] = pf[i - 1] + (!prime[a[i]]);
    }
    while (t--){
        int u, v;
        cin >> u >> v;
        cout << pf[v] - pf[u - 1] << "\n";
    }
    return 0;
}