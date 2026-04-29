// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cppb1p507"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll f[50];

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
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n];
    return 0;
}