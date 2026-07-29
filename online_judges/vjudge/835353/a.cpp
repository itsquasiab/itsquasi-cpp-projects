// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "a"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr];
int n, k;
ll check(ll sumlimit){
    ll res = 0;
    int cnt = 1;
    for (int i = 1; i <= n; ++i){
        if (res + a[i] > sumlimit){
            cnt++;
            res = 0;
        }
        res += a[i];
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
    ll l = 1, r = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], l = max(l, a[i]), r += a[i];
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