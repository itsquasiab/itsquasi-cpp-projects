// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll m, n;
    cin >> m >> n;
    cout << __gcd(m, n) << "\n" << m * n / __gcd(m, n);
    return 0;
}