// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "maxdiff"

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
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll mn = a[1];
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        sum = max(sum, max(a[i] - mn, a[i] - a[i]));
        mn = min(mn, a[i]);
    }
    cout << sum;
    return 0;
}