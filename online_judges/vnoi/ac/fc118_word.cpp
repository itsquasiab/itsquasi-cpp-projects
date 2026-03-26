// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "fc118_word"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 131;

unordered_map<ll, bool> exist;

ll make_hash(int n, string s){
    ll hs = 0;
    for (int i = 1; i <= n; ++i){
        hs = (hs * base + (s[i] - 'A' + 1)) % mod;
    }
    return hs;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        string a;
        cin >> a;
        int sz = a.size();
        a = ' ' + a;
        ll hs = make_hash(sz, a);
        exist[hs] = 1;
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i){
        string a;
        cin >> a;
        int sz = a.size();
        a = ' ' + a;
        ll hs = make_hash(sz, a);
        cout << (exist[hs] ? "YES\n" : "NO\n");
    }
    return 0;
}