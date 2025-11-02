//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MIN, base = 31;

ll h1[arr], h2[arr], pw[arr];

ll get1(int i, int j){
    return (h1[j] - h1[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

ll get2(int i, int j){
    return (h2[j] - h2[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    string rev = a;
    reverse(rev.begin(), rev.end());
    rev = ' ' + rev;
    a = ' ' + a;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        h1[i] = (h1[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int i = 1; i <= n; ++i){
        h2[i] = (h2[i - 1] * base + (rev[i] - 'a' + 1)) % mod;
    }
    int res = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            ll h1 = get1(i, j);
            ll h2 = get2(n - j + 1, n - i + 1);
            if (h1 == h2){
                res = max(res, j - i + 1);
            }
        }
    }
    cout << res;
    return 0;
}