// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

ll pf[arr];

unordered_map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = " " + a;
    for (int i = 1; i <= n; ++i){
        pf[i] = pf[i - 1];
        if (a[i] == 'R') pf[i]++;
        else if (a[i] == 'B') pf[i]--;
    }
    cnt[0] = 1;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        res += cnt[pf[i]];
        cnt[pf[i]]++;
    }
    cout << res;
    return 0;
}