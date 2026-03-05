// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "vostr"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int m, n;
string a, b;

ll hsa[arr], hsb[arr], pwa[arr], pwb[arr];

void make_hash(){
    hsa[0] = 0;
    hsb[0] = 0;
    pwa[0] = 1;
    pwb[0] = 1;
    for (int i = 1; i <= m; ++i){
        hsa[i] = (hsa[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        pwa[i] = (pwa[i - 1] * base) % mod;
    }
    for (int i = 1; i <= n; ++i){
        hsb[i] = (hsb[i - 1] * base + (b[i] - 'a' + 1)) % mod;
        pwb[i] = (pwb[i - 1] * base) % mod;
    }
}

ll get_hash1(int i, int j){
    return (hsa[j] - hsa[i - 1] * pwa[j - i + 1] + mod * mod) % mod;
}

ll get_hash2(int i, int j){
    return (hsb[j] - hsb[i - 1] * pwb[j - i + 1] + mod * mod) % mod;
}

void compare(int l, int r, int u, int v){
    ll l1 = r - l + 1;
    ll l2 = v - u + 1;
    ll mnlen = min(l1, l2);
    int lw = 0, hh = mnlen;
    while (lw < hh){
        int mid = (lw + hh + 1) >> 1;
        if (get_hash1(l, l + mid - 1) == get_hash2(u, u + mid - 1)) lw = mid;
        else hh = mid - 1;
    }
    ll lcp = lw;
    if (lcp == mnlen){
        if (l1 == l2) cout << "=";
        else if (l1 < l2) cout << "<";
        else cout << ">";
    }
    else {
        if (a[l + lcp] < b[u + lcp]) cout << "<";
        else cout << ">";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> m >> n >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    make_hash();
    int k;
    cin >> k;
    while (k--){
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        compare(l, r, u, v);
    }
    return 0;
}