// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "1258"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll hsa[arr], hsr[arr], pw[arr];

void make_hash(string a, string r, int n){
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        pw[i] = (pw[i - 1] * base) % mod;
        hsa[i] = (hsa[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        hsr[i] = (hsr[i - 1] * base + (r[i] - 'a' + 1)) % mod;
    }
}

ll gh1(int i, int j){
    return (hsa[j] - hsa[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

ll gh2(int i, int j){
    return (hsr[j] - hsr[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcases;
    cin >> testcases;
    for (int cases = 1; cases <= testcases; ++cases){
        string a;
        cin >> a;
        string r = a;
        reverse(r.begin(), r.end());
        int n = a.size();
        a = " " + a;
        r = " " + r;
        make_hash(a, r, n);
        ll res = 0;
        for (int i = 1; i <= n; ++i){
            if (gh1(i, n) == gh2(1, n - i + 1)){
                res = n - i + 1 + ((i * 2) - 2);
                break;
            }
        }
        cout << "Case " << cases << ": " << res << "\n";
    }
    return 0;
}