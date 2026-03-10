// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll hash_a[arr], hash_b[arr], pwa[arr], sza, szb;

void get_hash(string a, string b){
    pwa[0] = 1;
    for (int i = 1; i <= sza; ++i){
        pwa[i] = (pwa[i - 1] * base) % mod;
    }
    hash_a[0] = 0;
    for (int i = 1; i <= sza; ++i){
        hash_a[i] = (hash_a[i - 1] * base + (a[i] - 'a' + 1)) % mod;
    }
    hash_b[0] = 0;
    for (int i = 1; i <= szb; ++i){
        hash_b[i] = (hash_b[i - 1] * base + (b[i] - 'a' + 1)) % mod;
    }
}

ll hs_a(int pos1, int pos2){
    return (hash_a[pos2] - hash_a[pos1 - 1] * pwa[pos2 - pos1 + 1] % mod + mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    string a, b;
    cin >> a >> b;
    sza = a.size();
    szb = b.size();
    a = ' ' + a;
    b = ' ' + b;
    get_hash(a, b);
    for (int i = szb; i <= sza; ++i){
        int pos1 = i - szb + 1, pos2 = i;
        if (hs_a(pos1, pos2) == hash_b[szb]) cout << pos1 << " ";
    }
    return 0;
}