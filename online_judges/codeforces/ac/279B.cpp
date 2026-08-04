// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "279B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int l = 1, r = 1, res = 0;
    while (r <= n){
        t -= a[r];
        while (t < 0){
            t += a[l];
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    cout << res;
    return 0;
}