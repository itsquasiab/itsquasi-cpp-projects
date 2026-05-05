// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "BOBASO"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll s1[arr], s2[arr];

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
    }
    s1[1] = a[1];
    for (int i = 2; i <= n; ++i){
        s2[i] = 2 * a[i] + 3 * s1[i - 1];
        s1[i] = max(s1[i - 1], a[i]);
    }
    ll res = 0, mx = s2[2];
    for (int i = 3; i <= n; ++i){
        res = max(res, mx - 5 * a[i]);
        mx = max(mx, s2[i]);
    }
    cout << res;
    return 0;
}