//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll n, s;
pair<ll, ll> a[arr];

bool comp(pair<ll,ll> s, ll t){
    return s.first < t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        ll target = s - a[i].first;
        int t = lower_bound(a + 1, a + 1 + n, target, comp) - a;
        if (a[t].first == target && t != i){
            cout << a[i].second << " " << a[t].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}