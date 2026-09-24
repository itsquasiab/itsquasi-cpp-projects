// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cdl1p5"

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
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = a + b + c;
    ll y = a * a + b * b + c * c;
    cout << "Tong ba so: " << x << "\nTong binh phuong ba so: " << y;
    return 0;
}