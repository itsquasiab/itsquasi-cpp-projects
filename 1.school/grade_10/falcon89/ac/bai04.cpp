//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 5e5 + 6, mod = 1e9 + 7, base = 31, arr2 = 1e5 + 6;

ll a[arr], b[arr];
ll bit[arr];

void update(int i, ll val) {
    for (; i < arr; i += i & -i)
        bit[i] = max(bit[i], val);
}
ll get(int i) {
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll len = n * k;

    for (int i = 1; i <= n * k; ++i) cin >> a[i];
    for (int i = 1; i <= n * k; ++i) cin >> b[i];

    vector<vector<ll>> pos(arr2);
    for (int i = 1; i <= len; ++i)
        pos[b[i]].push_back(i);

    ll mx = 0;

    for (int i = len; i >= 1; --i) {
        ll v = a[i];
        for (ll p : pos[v]) {
            int idx = len - p + 1;
            ll ddc = get(idx - 1) + 1;
            update(idx, ddc);
            mx = max(mx, ddc);
        }
    }
    cout << mx;
    return 0;
}