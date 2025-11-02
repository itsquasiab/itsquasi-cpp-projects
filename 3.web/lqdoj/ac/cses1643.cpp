//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll sumsofar = a[1], sum = a[1];
    for (int i = 2; i <= n; ++i){
        sumsofar = max(a[i], sumsofar + a[i]);
        sum = max(sum, sumsofar);
    }
    cout << sum;
    return 0;
}