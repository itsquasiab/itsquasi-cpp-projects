// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "olp4slkca"

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
    ll three = c;
    ll one_two = min(a, b);
    ll one = (a > one_two ? (a - one_two) / 3 : 0);
    //cout << three << " " << one_two << " " << one << "\n";
    cout << three + one_two + one;
    return 0;
}