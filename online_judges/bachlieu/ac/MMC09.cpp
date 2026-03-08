// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i){
        if (i == x) continue;
        cout << a[i] << " ";
    }
    return 0;
}