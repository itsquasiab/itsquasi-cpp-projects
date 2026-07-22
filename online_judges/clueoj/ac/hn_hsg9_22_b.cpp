// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "hn_hsg9_22_b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, bs = 31;

ll hsa = 0, hss[arr], pw[arr];
string s, a;

ll get(int i, int j){
    return (hss[j] - hss[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> s >> a;
    int n = s.size(), m = a.size();
    s = " " + s, a = " " + a;
    pw[0] = 1;
    hss[0] = 0;
    for (int i = 1; i <= n; ++i){
        hss[i] = (hss[i - 1] * bs + (s[i] - 'A' + 1)) % mod;
        pw[i] = (pw[i - 1] * bs) % mod;
    }
    for (int i = 1; i <= m; ++i){
        hsa = (hsa * bs + (a[i] - 'A' + 1)) % mod;
    }
    ll res = 0;
    for (int i = m; i <= n; ++i){
        if (get(i - m + 1, i) == hsa){
            res++;
            i += m - 1;
        }
    }
    cout << res;
    return 0;
}