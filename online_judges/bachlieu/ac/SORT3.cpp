// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int n2 = n * 2;
    for (int i = 1; i <= n2; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    sort(a + 1 + n, a + 1 + n2, greater<ll>());
    for (int i = 1; i <= n2; ++i) cout << a[i] << " ";
    return 0;
}