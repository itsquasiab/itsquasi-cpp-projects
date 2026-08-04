// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1873E"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool check(ll mid, ll a[], int n, ll x){
    ll water = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] < mid) water += mid - a[i];
    }
    return water <= x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        ll x;
        cin >> n >> x;
        ll a[n + 1];
        ll l = 1, r = 2000000000, h = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        while (l <= r){
            ll mid = (l + r) >> 1;
            if (check(mid, a, n, x)){
                h = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << h << "\n";
    }
    return 0;
}