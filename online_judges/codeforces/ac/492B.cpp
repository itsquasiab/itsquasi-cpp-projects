//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, len;
    cin >> n >> len;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    long double l = a[1], r = len - a[n];
    long double mx = max(l, r);
    for (int i = 1; i < n; ++i){
        long double mid = (a[i + 1] - a[i]) / 2.0;
        mx = max(mx, mid);
    }
    if (mx == 0) mx++;
    cout << fixed << setprecision(10) << mx;
    return 0;
}