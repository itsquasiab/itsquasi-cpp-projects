// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "paper"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll sum(ll x){
    ll t = 0;
    while (x){
        t += x % 10;
        x /= 10;
    }
    return t % 3;
}

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
        int n;
        cin >> n;
        int md0 = 0, md1 = 0, md2 = 0;
        for (int i = 1; i <= n; ++i){
            ll a;
            cin >> a;
            if (sum(a) == 0) md0++;
            else if (sum(a) == 1) md1++;
            else md2++;
        }
        cout << min(md1, md2) + md0 / 2 << "\n";
    }
    return 0;
}