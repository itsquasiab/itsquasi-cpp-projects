// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
#define task "palinstr"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string a;
ll hash_r, hash_a, m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a;
    string r = a;
    reverse(r.begin(), r.end());
    m = a.size();
    a = ' ' + a;
    r = ' ' + r;
    hash_a = 0;
    hash_r = 0;
    for (int i = 1; i <= m; ++i){
        hash_a = (hash_a * base + (a[i] - 'a' + 1)) % mod;
        hash_r = (hash_r * base + (r[i] - 'a' + 1)) % mod;
    }
    if (hash_a == hash_r)
    cout << "YES\n";
    else cout << "NO\n";
    return 0;
}