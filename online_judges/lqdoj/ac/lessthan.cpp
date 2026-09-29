// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "lessthan"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

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
        b[i] = a[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(a + 1, a + 1 + n, b[i]) - a;
        if (a[j] == b[i]) j--;
        cout << j << " ";
    }
    return 0;
}