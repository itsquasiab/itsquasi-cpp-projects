// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long
#define task "doixung"

using namespace std;

const ll arr = 1e6 + 6, md1 = 1e9 + 7, md2 = 1e9 + 9, bs1 = 31, bs2 = 131;

ll hs[arr], hr[arr];
ll hs2[arr], hr2[arr];
ll pw[arr], pw2[arr];
string s, r;
int n;

void make_hash(){
    pw[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= n; ++i){
        hs[i] = (hs[i - 1] * bs1 + (s[i] - 'a' + 1)) % md1;
        hr[i] = (hr[i - 1] * bs1 + (r[i] - 'a' + 1)) % md1;
        hs2[i] = (hs2[i - 1] * bs2 + (s[i] - 'a' + 1)) % md2;
        hr2[i] = (hr2[i - 1] * bs2 + (r[i] - 'a' + 1)) % md2;
        pw[i] = (pw[i - 1] * bs1) % md1;
        pw2[i] = (pw2[i - 1] * bs2) % md2;
    }
}

pair<ll, ll> get_hash1(int i, int j){
    ll h1 = (hs[j] - hs[i - 1] * pw[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hs2[j] - hs2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
    return {h1, h2};
}

pair<ll, ll> get_hash2(int i, int j){
    ll h1 = (hr[j] - hr[i - 1] * pw[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hr2[j] - hr2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
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
    cin >> n >> s;
    r = s;
    reverse(r.begin(), r.end());
    s = ' ' + s;
    r = ' ' + r;
    make_hash();
    int t = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            pair<ll, ll> h1 = get_hash1(i, j);
            pair<ll, ll> h2 = get_hash2(n - j + 1, n - i + 1);
            if (h1.first == h2.first && h1.second == h2.second) t = max(t, j - i + 1);
        }
    }
    cout << t;
    return 0;
}