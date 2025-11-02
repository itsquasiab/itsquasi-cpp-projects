//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("meet.inp","r"))
    {
        freopen("meet.inp", "r", stdin);
        freopen("meet.out", "w", stdout);
    }
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    while (q--){
        ll x, y;
        cin >> x >> y;
        ll l = x, r = y;
        ll res = LLONG_MAX;
        while (l <= r){
            ll z = l + r >> 1;
            ll res1 = abs(a[x] - a[z]), res2 = abs(a[y] - a[z]);
            if (res1 == res2){
                res = min(res, res1);
                break;
            }
            else if (res1 < res2){
                res = min(res, res2);
                l = z + 1;
            }
            else if (res1 > res2){
                res = min(res, res1);
                r = z - 1;
            }
            //cout << res1 << " " << res2 << "\n";
        }
        cout << res << "\n";
    }
    return 0;
}