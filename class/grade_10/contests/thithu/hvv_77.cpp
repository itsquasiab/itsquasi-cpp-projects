//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 2e6 + 6, mod = 1e9 + 7;

int n, d;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("hopqua.inp","r"))
    {
        freopen("hopqua.inp", "r", stdin);
        freopen("hopqua.out", "w", stdout);
    }
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    ll res = 0;
    for (int i = 1; i <= n - 2; ++i){
        int j = upper_bound(a + i + 2, a + 1 + n, a[i] + d) - a - 1;
        ll t = (j - i);
        t = t * (t - 1) / 2;
        res += t;
        //cout << t << "\n";
    }
    cout << res;
    return 0;
}