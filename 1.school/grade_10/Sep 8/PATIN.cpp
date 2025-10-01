//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

pair<ll,ll> a[arr];
ll b[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, r, q;
    cin >> n >> r >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= q; ++i){
        cin >> b[i];
    }
    return 0;
}