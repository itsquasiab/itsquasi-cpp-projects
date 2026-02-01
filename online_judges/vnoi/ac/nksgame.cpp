//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], b[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + n);
    int i = 1, j = n;
    ll mx = LLONG_MAX;
    while (i <= n && j >= 1){
        ll sum = a[i] + b[j];
        ll asum = abs(sum);
        mx = min(mx, asum);
        if (sum > 0) j--;
        else i++;
    }
    cout << mx;
    return 0;
}