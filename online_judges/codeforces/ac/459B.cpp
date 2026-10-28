// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "459B"

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
    ll n;
    cin >> n;
    ll mx = -1e9, mn = 1e9;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    cout << mx - mn << " ";
    if (mx == mn){
        cout << n * (n - 1) / 2;
        return 0;
    }
    ll cntmx = 0, cntmn = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] == mx) cntmx++;
        else if (a[i] == mn) cntmn++;
    }
    cout << cntmx * cntmn << "\n";
    return 0;
}