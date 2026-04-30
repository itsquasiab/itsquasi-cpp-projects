#include <bits/stdc++.h>
#define ll long long
#define task "honuoc"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

pair<ll, ll> a[arr];
ll subarr[arr];

int main(){
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> n >> t;
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }
    cout << sum << "\n";
    for (int j = 1; j <= t; ++j){
        ll itsquasi1 = 0;
        for (int i = 1; i <= n; ++i){
            ll itsquasi2 = min(a[i].second, a[i].first);
            itsquasi1 += itsquasi2;
            a[i].first -= itsquasi2;
        }
        cout << sum - itsquasi1 << "\n";
        sum -= itsquasi1;
    }
    return 0;
}
