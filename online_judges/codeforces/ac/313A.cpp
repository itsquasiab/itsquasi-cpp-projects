// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "313A"

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
    ll a;
    cin >> a;
    if (a > 0){
        cout << a;
        return 0;
    }
    ll mx = a;
    mx = max(mx, a / 10);
    mx = max(mx, (a / 100) * 10 + a % 10);
    cout << mx;
    return 0;
}