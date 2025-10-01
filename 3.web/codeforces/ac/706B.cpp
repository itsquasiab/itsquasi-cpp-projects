//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        ll b;
        cin >> b;
        cout << upper_bound(a + 1, a + 1 + n, b) - a - 1 << "\n";
    }
    return 0;
}