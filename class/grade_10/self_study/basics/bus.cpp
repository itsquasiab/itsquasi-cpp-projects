// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bus"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll d, t;
    cin >> n >> d >> t;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        int l = 1, r = 1000001, res = 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            ll exp = t + (mid - 1) * d;
            if (exp >= a){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << res << " ";
    }
    return 0;
}