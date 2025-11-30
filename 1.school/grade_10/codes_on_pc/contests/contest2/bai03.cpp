#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, k;
ll a[arr];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll sum = 0;
    int res = INT_MAX;
    for (int i = 1, j = 1; j <= n; ++j){
        sum += a[j];
        while (sum >= k){
            res = min(res, j - i + 1);
            sum -= a[i];
            i++;
        }
    }
    cout << res;
    return 0;
}
