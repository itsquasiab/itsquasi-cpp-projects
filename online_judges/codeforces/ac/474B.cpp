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
        a[i] += a[i - 1];
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        ll t;
        cin >> t;
        int l = 1, r = n, res = 1;
        while(l <= r){
            int mid = l + r >> 1;
            if (a[mid] >= t){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << res << "\n";
    }
    return 0;
}