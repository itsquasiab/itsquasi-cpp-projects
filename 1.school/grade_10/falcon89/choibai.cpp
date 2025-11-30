#include<bits/stdc++.h>
#define ll long long
#define fname "choibai"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
ll a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(fname".inp","r")){
        freopen(fname".inp","r",stdin);
        freopen(fname".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<ll> evens, odds;
    sort(a + 1, a + 1 + n, greater<ll>());
    for (int i = 1; i <= n; ++i){
        if (a[i] % 2 == 0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
    }
    if (evens.size() < k && odds.size() < k){
        cout << 0;
        return 0;
    }
    ll sum1 = 0, sum2 = 0;
    if (evens.size() >= k){
        for (int i = 0; i < k; ++i){
            sum1 += evens[i];
        }
    }
    if (odds.size() >= k){
        for (int i = 0; i < k; ++i){
            sum2 += odds[i];
        }
    }
    cout << max(sum1, sum2);
}
