// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "bieuthuc"

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
        ll a, b, c;
        cin >> a >> b >> c;
        ll r1 = a + b + c;
        ll r2 = a * b * c;
        ll r3 = a + b * c;
        ll r4 = a * b + c;
        ll r5 = (a + b) * c;
        ll r6 = a * (b + c);
        cout << max({r1, r2, r3, r4, r5, r6}) << "\n";
    }
    return 0;
}