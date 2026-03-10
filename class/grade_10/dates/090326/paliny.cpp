// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define task "paliny"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;
string r, a;

ll hsa[arr], hsr[arr], pw[arr];
int n;

void make_hash(){
    hsa[0] = 0;
    hsr[0] = 0;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        hsa[i] = (hsa[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        hsr[i] = (hsr[i - 1] * base + (r[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
}

ll get_hash1(int i, int j){
    return (hsa[j] - hsa[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

ll get_hash2(int i, int j){
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
    cin >> n >> a;
    r = a;
    reverse(r.begin(), r.end());
    a = ' ' + a;
    r = ' ' + r;
    make_hash();
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            if (get_hash1(i, j) == get_hash2(n - j + 1, n - i + 1)) res = max(res, j - i + 1);
        }
    }
    cout << res;
    return 0;
}