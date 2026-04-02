// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "twopointerib"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int m, n;
ll a[arr], b[arr];
vector<ll> c;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int i = 1, j = 1;
    while (i <= m && j <= n){
        if (a[i] < b[j]) i++;
        else {
            c.push_back(i - 1);
            j++;
        }
    }
    while (c.size() < n){
        c.push_back(m);
    }
    for (auto i : c) cout << i << " ";
    return 0;
}