//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

pair<ll, ll> a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("trans.inp","r"))
    {
        freopen("trans.inp", "r", stdin);
        freopen("trans.out", "w", stdout);
    }
    int n, m;
    ll k, r;
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= k; ++i){
        cin >> a[i].first >> a[i].second;
    }
    ll res = k + 1;
    cout << res;
    return 0;
}