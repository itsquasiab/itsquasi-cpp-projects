// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "np003"

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
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        if (a <= 1){
            cout << "YES\n";
            continue;
        }
        ll l = 2, r = 1000000;
        bool found = 0;
        while (l <= r){
            ll mid = (l + r) >> 1;
            ll pw = mid * mid * mid;
            if (pw == a){
                found = 1;
                break;
            }
            else if (pw < a) l = mid + 1;
            else r = mid - 1;
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}