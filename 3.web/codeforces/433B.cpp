//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pf1[arr], pf2[arr], b[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf1[i] = pf1[i - 1] + a[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        pf2[i] = pf2[i - 1] + a[i];
    }
    int m;
    cin >> m;
    while (m--){
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1){
            cout << pf1[r] - pf1[l - 1] << "\n";
        }
        else {
            cout << pf2[r] - pf2[l - 1] << "\n";
        }
    }
    return 0;
}