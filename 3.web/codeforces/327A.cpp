//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pf[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            ll part = pf[i] - pf[j - 1];
            part = (i - j + 1) - part;
            ll rem = pf[j - 1] + pf[n] - pf[i];
            sum = max(sum, rem + part);
        }
    }
    cout << sum;
    return 0;
}