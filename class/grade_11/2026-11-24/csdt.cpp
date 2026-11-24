// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "csdt"

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
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll mn = n + (n & 1 ? 1 : 2);
        ll mx = (n - 1) * 2;
        ll total_num = (mx - mn) / 2 + 1;
        ll res = (total_num + 1) * total_num / 2;
        /*for (ll i = mn; i <= mx; i += 2){
            ll l = i / 2 - 1, r = i / 2 + 1;
            ll lmn = i - n;
            ll rmx = i - lmn;
            res += (rmx - lmn) / 2;
        }*/
        cout << res << "\n";
    }
    return 0;
}