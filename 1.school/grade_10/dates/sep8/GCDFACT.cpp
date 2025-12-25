//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

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
        ll gcd1 = LLONG_MAX, gcd2 = 0;
        for (int i = 1; i <= n; ++i){
            gcd2 = __gcd(gcd2, a[i]);
            gcd1 = min(gcd1, a[i]);
        }
        if (gcd1 == gcd2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}