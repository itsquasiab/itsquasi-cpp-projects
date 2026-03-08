// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    long double a;
    cin >> a;
    long double s = 0;
    ll i = 1;
    while (s <= a){
        s = s + 1.0 / i;
        ++i;
    }
    cout << i - 1;
    return 0;
}