// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "substr"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll pw[arr], hsa[arr], hsb = 0;

string a, b;
int n, m;

void make_hash(){
    pw[0] = 1;
    hsa[0] = 0;
    for (int i = 1; i <= n; ++i){
        pw[i] = (pw[i - 1] * base) % mod;
        hsa[i] = (hsa[i - 1] * base + (a[i] - '0' + 1)) % mod;
    }
    for (int i = 1; i <= m; ++i){
        hsb = (hsb * base + (b[i] - '0' + 1)) % mod;
    }
}

ll get_hash(int i, int j){
    return (hsa[j] - hsa[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    make_hash();
    for (int i = 1; i <= n - m + 1; ++i){
        //cout << get_hash1(l, r) << " " << get_hash2(n - r + 1, n - l + 1) << "\n";
        if (get_hash(i, i + m - 1) == hsb) cout << i << " ";
    }
    return 0;
}