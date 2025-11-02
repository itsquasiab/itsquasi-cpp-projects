//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 3, inf = LLONG_MIN, base = 31;

ll pw[arr], h1[arr], h2[arr];

void precompute(int len, string s){
    pw[0] = 1;
    for (int i = 1; i <= len; ++i){
        h1[i] = (h1[i - 1] * base + (s[i] - 'a' + 1)) % mod;
        pw[i] = pw[i - 1] * base % mod;
    }

    reverse(s.begin() + 1, s.end());
    for (int i = 1; i <= len; ++i){
        h2[i] = (h2[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    }
}

ll get1(int l, int r){
    return (h1[r] - h1[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
ll get2(int l, int r){
    return (h2[r] - h2[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int len = s.size();
    s = ' ' + s;

    precompute(len, s);

    int n;
    cin >> n;
    while(n--){
        ll l, r;
        cin >> l >> r;
        ll hash1 = get1(l, r);
        ll hash2 = get2(len - r + 1, len - l + 1);
        if (hash1 == hash2) cout << "1\n";
        else cout << "-1\n";
    }
    return 0;
}