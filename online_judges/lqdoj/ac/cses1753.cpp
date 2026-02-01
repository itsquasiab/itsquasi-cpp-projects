//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define infmin LLONG_MIN
#define infmax LLONG_MAX

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll ht, hs[arr], pw[arr];

ll gethash(int i, int j){
    return (hs[j] - hs[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    for (int i = 0; i < t.size(); ++i){
        ht = (ht * base + (t[i] - 'a' + 1)) % mod;
    }
    pw[0] = 1;
    for (int i = 1; i < s.size(); ++i){
        hs[i] = (hs[i - 1] * base + (s[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    ll cnt = 0;
    for (int i = 1; i <= s.size() - t.size(); ++i){
        if (ht == gethash(i, i + t.size() - 1)) cnt++;
    }
    cout << cnt;
    return 0;
}