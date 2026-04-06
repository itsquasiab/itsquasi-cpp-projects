// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "students"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] >= 38){
            ll tmp = (a[i] / 5) + (a[i] % 5 == 0 ? 0 : 1);
            tmp = tmp * 5;
            if (tmp - a[i] <= 2) a[i] = tmp;
        }
    }
    sort(a + 1, a + 1 + n, greater<ll>());
    for (int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
    return 0;
}