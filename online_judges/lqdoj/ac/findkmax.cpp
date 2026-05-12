// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "findkmax"

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
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] = a[i] * (n - i + 1);
    }
    sort (a + 1, a + 1 + n);
    ll sum = 0;
    int i = 1;
    while (i <= n){
        sum += a[i];
        if (sum > x) break;
        i++;
    }
    cout << i - 1;
    return 0;
}