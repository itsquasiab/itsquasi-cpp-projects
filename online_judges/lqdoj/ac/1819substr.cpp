// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "1819substr"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll pf[arr];
unordered_map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int k;
    string a;
    cin >> k >> a;
    a = " " + a;
    pf[0] = 0;
    cnt[0] = 1;
    ll res = 0;
    for (int i = 1; i < a.size(); ++i){
        pf[i] = pf[i - 1] + (a[i] - '0');
        res += cnt[pf[i] - k];
        cnt[pf[i]]++;
    }
    cout << res;
    return 0;
}