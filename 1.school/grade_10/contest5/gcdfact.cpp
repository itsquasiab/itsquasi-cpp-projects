//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr];

ll gt(ll x){
    ll res = 1;
    while (x > 1){
        res *= x;
        x--;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll gcd1 = 0, gcd2 = LLONG_MAX;
        for (int i = 1; i <= n; ++i){
            gcd1 = __gcd(gcd1, a[i]);
            gcd2 = min(gcd2, a[i]);
        }
        if (gcd1 == gcd2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}