#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll k, a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 1; i <= n - k + 1; ++i){
        ll g = a[i];
        ll pf = a[i];
        if (k > 1)
        for (int j = i + 1; j <= i + k; ++j){
            g = __gcd(g, a[j]);
            pf += a[j];
        }
        res = max(res, g * pf);
        for (int j = i + k + 1; j <= n; ++j){
            g = __gcd(g, a[j]);
            pf += a[j];
            res = max(res, g * pf);
        }
    }
    cout << res;
    return 0;
}