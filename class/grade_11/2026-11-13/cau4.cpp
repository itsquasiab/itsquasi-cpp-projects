#include <bits/stdc++.h>
#define ll long long
#define task "cau4"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
int n, k;

ll check(ll mid){
    ll towers = 1, radius = a[0] + mid * 2;
    for (int i = 1; i <= n; ++i){
        if (a[i] > radius){
            radius = a[i] + mid * 2;
            towers++;
        }
    }
    return towers;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    ll l = 0, r = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        r = max(r, a[i]);
    }
    if (n == k){
        cout << 0;
        return 0;
    }
    sort (a + 1, a + 1 + n);
    ll res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (check(mid) <= k){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}
