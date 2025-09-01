//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

unordered_map<ll,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll mx = 0;
    while(n--){
        ll a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, cnt[a]);
    }
    ll res = LLONG_MAX;
    for (auto i : cnt){
        if (i.second == mx) res = min(res, i.first);
    }
    cout << res;
    return 0;
}