// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "express"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
ll pf[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    ll res = 0;
    for (int i = 2; i <= n; ++i){
        ll tmp = a[i] * a[i - 1];
        for (int j = i + 1; j <= n; ++j){
            ll tmp2 = tmp;
            if (j == i + 1){
                tmp2 *= a[j];
            }
            else {
                tmp2 += (pf[j - 2] - pf[i]) + a[j] * a[j - 1];
            }
            res = max(res, pf[i - 2] + tmp2 + (pf[n] - pf[j]));
        }
    }
    cout << res;
    return 0;
}