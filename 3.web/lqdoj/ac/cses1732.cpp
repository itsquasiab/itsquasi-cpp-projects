//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define infmin LLONG_MIN
#define infmax LLONG_MAX

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll h1[arr], pw[arr];

ll gethash(int i, int j){
    return (h1[j] - h1[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a;
    cin >> a;
    int n = a.size();
    a = ' ' + a;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i){
        h1[i] = (h1[i - 1] * base + (a[i] - 'a' + 1)) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int i = 1; i < n; ++i){
        if (gethash(1, i) == gethash(n - i + 1, n)) cout << i << " ";
    }
    return 0;
}