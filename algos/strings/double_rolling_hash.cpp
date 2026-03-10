// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <utility>
#define ll long long
#define task "double_rolling_hash"

using namespace std;

const ll arr = 1e6 + 6, md1 = 1e9 + 7, md2 = 1e9 + 9, bs1 = 131, bs2 = 311;

string a, b;
ll hsa1[arr], hsb1, pw1[arr];
ll hsa2[arr], hsb2, pw2[arr];
int m, n;

void make_hash(){
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= m; ++i){
        hsa1[i] = (hsa1[i - 1] * bs1 + (a[i] - 'a' + 1)) % md1;
        hsa2[i] = (hsa2[i - 1] * bs2 + (a[i] - 'a' + 1)) % md2;
        pw1[i] = (pw1[i - 1] * bs1) % md1;
        pw2[i] = (pw2[i - 1] * bs2) % md2;
    }
    for (int i = 1; i <= n; ++i){
        hsb1 = (hsb1 * bs1 + (b[i] - 'a' + 1)) % md1;
        hsb2 = (hsb2 * bs2 + (b[i] - 'a' + 1)) % md2;
    }
}

pair<ll, ll> get_hash(int i, int j){
    ll h1 = (hsa1[j] - hsa1[i - 1] * pw1[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hsa2[j] - hsa2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
    return {h1, h2};
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a >> b;
    m = a.size();
    n = b.size();
    a = ' ' + a;
    b = ' ' + b;
    make_hash();
    for (int j = n; j <= m; ++j){
        int i = j - n + 1;
        if (get_hash(i, j) == make_pair(hsb1, hsb2)) cout << i << " ";
    }
    return 0;
}