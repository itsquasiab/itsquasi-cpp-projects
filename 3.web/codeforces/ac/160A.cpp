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
    }
    sort (a + 1, a + 1 + n, greater<ll>());
    for (int i = 1; i <= n; ++i){
        pf[i] = pf[i - 1] + a[i];
    }
    int l = 1, r = n, res = 0;
    while (l <= r){
        int mid = l + r >> 1;
        if (pf[mid] > pf[n] - pf[mid]){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}