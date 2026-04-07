// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "numbers"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll prdvs(ll n){
    ll t = 0;
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0){
            n /= i;
            t += i;
        }
    }
    if (n > 1) t += n;
    return t;
}

ll sumdg(ll n){
    ll t = 0;
    while (n){
        t += n % 10;
        n /= 10;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << (prdvs(n) == sumdg(n) ? 1 : 0) << "\n";
    }
    return 0;
}