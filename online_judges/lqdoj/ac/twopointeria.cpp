// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "twopointeria"

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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= m; ++j) cin >> b[j];
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + m);
    int i = 1, j = 1;
    vector<ll> c;
    while (i <= n && j <= m){
        if (a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
    }
    while (i <= n) c.push_back(a[i]), i++;
    while (j <= m) c.push_back(b[j]), j++;
    for (auto x : c) cout << x << " ";
    return 0;
}