// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "seqhh"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], pf[arr];
unordered_map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    pf[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    ll res = 0;
    cnt[0] = 1;
    /*for (int i = 1; i <= n; ++i){
        for (int j = 0; j < i; ++j){
            if (pf[i] - pf[j] == k) res++;
        }
    }*/
    for (int i = 1; i <= n; ++i){
        res += cnt[pf[i] - k];
        cnt[pf[i]]++;
    }
    cout << res;
    return 0;
}