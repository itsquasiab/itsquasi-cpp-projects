#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 3006, mod = 1e9 + 7;

pair<ll, ll> a[arr];
ll dp[arr][arr];

bool sorter(pair<ll,ll> a, pair<ll,ll> b){
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, sorter);
    ll mx = 1;
    pair<ll,ll> last = make_pair(a[1].first, a[1].second);
    for (int i = 2; i <= n; ++i){
        if (a[i].first >= last.first && a[i].second <= last.second){
            mx++;
            last = make_pair(a[i].first, a[i].second);
        }
    }
    cout << mx;
    return 0;
}

