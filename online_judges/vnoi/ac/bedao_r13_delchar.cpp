// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <map>
#define ll long long
#define ii pair<ll, ll>
#define task "bedao_r13_delchar"

using namespace std;

const ll arr = 1e6 + 6, mod1 = 1e9 + 7, mod2 = 1e9 + 9, base1 = 31, base2 = 131;

map<ii, ll> cnt;

ll ha1[arr], ha2[arr], pw1[arr], pw2[arr];
string a;
int n;

void make_hash(){
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; ++i){
        pw1[i] = (pw1[i - 1] * base1) % mod1;
        pw2[i] = (pw2[i - 1] * base2) % mod2;
        ha1[i] = (ha1[i - 1] * base1 + (a[i] - 'a' + 1)) % mod1;
        ha2[i] = (ha2[i - 1] * base2 + (a[i] - 'a' + 1)) % mod2;
    }
}

ii get_hash(int i, int j){
    ll h1 = (ha1[j] - ha1[i - 1] * pw1[j - i + 1] + mod1 * mod1) % mod1;
    ll h2 = (ha2[j] - ha2[i - 1] * pw2[j - i + 1] + mod2 * mod2) % mod2;
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
    cin >> n >> a;
    a = ' ' + a;
    make_hash();
    for (int i = 1; i <= n; ++i){
        ii head = get_hash(1, i - 1);
        ii tail = get_hash(i + 1, n);
        ll hs1 = (head.first * pw1[n - i] % mod1 + tail.first) % mod1;
        ll hs2 = (head.second * pw2[n - i] % mod2 + tail.second) % mod2;
        cnt[{hs1, hs2}]++;
        //cout << hs << " ";
    }
    ll res = 0;
    for (auto i : cnt){
        res += i.second * (i.second - 1) >> 1;
    }
    cout << res;
    return 0;
}