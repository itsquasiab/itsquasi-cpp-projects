// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "977C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int n, k;
int check(ll mid){
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] <= mid) cnt++;
        else break;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    ll l = 1, r = 1e9;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        //cout << check(mid) << " ";
        if (check(mid) <= k){
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (a[i] <= res) cnt++;
        else break;
    }
    if (cnt == k && res >= 1) cout << res;
    else cout << -1;
    return 0;
}