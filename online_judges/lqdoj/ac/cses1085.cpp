// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cses1085"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

bool check(ll x, int n, int k){
    ll sum = 0, div = 1;
    for (int i = 1; i <= n; ++i){
        if (sum + a[i] > x){
            sum = 0;
            div++;
        }
        sum += a[i];
    }
    return div <= k;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    ll l = 0, r = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (check(mid, n, k)){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << l;
    return 0;
}