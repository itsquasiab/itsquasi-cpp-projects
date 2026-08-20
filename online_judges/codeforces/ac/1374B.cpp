// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1374B"

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
        int st = 0;
        while (n > 1){
            if (n % 6 != 0) n *= 2;
            else n /= 6;
            //cout << n << " ";
            st++;
        }
        if (n == 1) cout << st << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}