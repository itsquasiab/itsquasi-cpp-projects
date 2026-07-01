// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "foundstring"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, bs = 31;

ll ha = 0, hb[arr], pw[arr];
vector<ll> valid;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i <= n; ++i){
        ha = (ha * bs + (a[i] - 'a' + 1)) % mod;
    }
    pw[0] = 1;
    for (int i = 1; i <= m; ++i){
        hb[i] = (hb[i - 1] * bs + (b[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * bs) % mod;
    }
    for (int i = 1; i <= m - n + 1; ++i){
        ll get = (hb[i + n - 1] - hb[i - 1] * pw[n] + mod * mod) % mod;
        if (get == ha) valid.push_back(i);
    }
    cout << valid.size() << "\n";
    for (auto i : valid) cout << i << " ";
    return 0;
}
