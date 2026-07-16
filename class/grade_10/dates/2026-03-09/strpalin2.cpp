// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "strpalin"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll pw[arr], hsa[arr], hsr[arr];

string a, ra;
int n;

void make_hash(){
    pw[0] = 1;
    hsa[0] = 0;
    hsr[0] = 0;
    for (int i = 1; i <= n; ++i){
        pw[i] = (pw[i - 1] * base) % mod;
        hsa[i] = (hsa[i - 1] * base + (a[i] - '0' + 1)) % mod;
        hsr[i] = (hsr[i - 1] * base + (ra[i] - '0' + 1)) % mod;
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
    cin >> a;
    ra = a;
    reverse(ra.begin(), ra.end());
    n = a.size();
    a = ' ' + a;
    ra = ' ' + ra;
    make_hash();
    int k;
    cin >> k;
    while (k--){
        ll l, r;
        cin >> l >> r;
        //cout << get_hash1(l, r) << " " << get_hash2(n - r + 1, n - l + 1) << "\n";
        if (get_hash1(l, r) == get_hash2(n - r + 1, n - l + 1)) cout << "1\n";
        else cout << "-1\n";
    }
    return 0;
}