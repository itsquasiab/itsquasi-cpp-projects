// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ds08"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
bool check[arr];

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
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        if (check[i]) continue;
        int j = lower_bound(a + 1 + i, a + 1 + n, x - a[i]) - a;
        //cout << a[i] << " " << a[j] << "\n";
        if (check[j]) continue;
        if (a[i] + a[j] <= x){
            check[i] = check[j] = 1;
        }
        else check[i] = 1;
        res++;
    }
    cout << res;
    return 0;
}