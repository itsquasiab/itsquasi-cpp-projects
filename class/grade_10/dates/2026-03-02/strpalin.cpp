// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define task "strpalin"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7, base = 31;

ll hsa[arr], hsr[arr], pwa[arr], pwr[arr];
string a, r;
int n;

void make_hash(){
    hsa[0] = 0;
    hsr[0] = 0;
    pwa[0] = 1;
    pwr[0] = 1;
    for (int i = 1; i <= n; i++){
        hsa[i] = (hsa[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        hsr[i] = (hsr[i - 1] * base + (r[i] - 'a' + 1)) % mod;
        pwa[i] = (pwa[i - 1] * base) % mod;
        pwr[i] = (pwr[i - 1] * base) % mod;
    }
}

ll get_hash1(int i, int j){
    return (hsa[j] - hsa[i - 1] * pwa[j - i + 1] + mod * mod) % mod;
}

ll get_hash2(int i, int j){
    return (hsr[j] - hsr[i - 1] * pwr[j - i + 1] + mod * mod) % mod;
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
    r = a;
    reverse(r.begin(), r.end());
    n = a.size();
    a = ' ' + a;
    r = ' ' + r;
    make_hash();
    //cout << a << "\n" << r << "\n";
    int k;
    cin >> k;
    //cout << n << "\n";
    while(k--){
        int i, j;
        cin >> i >> j;
        ll hash_a = get_hash1(i, j);
        ll hash_r = get_hash2(n - j + 1, n - i + 1);
        cout << (hash_a == hash_r ? "1" : "-1") << "\n";
    }
    return 0;
}