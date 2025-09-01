//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr], f[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(f + 1, f + 1 + res, a[i]) - f;
        f[j] = a[i];
        res = max(res, j);
    }
    cout << res;
    return 0;
}