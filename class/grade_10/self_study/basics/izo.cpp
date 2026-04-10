// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "izo"

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
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort (a + 1, a + 1 + n);
    int l = 1, r = n;
    while (l < r){
        sum += a[r] - a[l];
        l++;
        r--;
    }
    cout << sum;
    return 0;
}