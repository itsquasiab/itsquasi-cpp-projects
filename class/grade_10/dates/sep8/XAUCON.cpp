//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll pf[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    string a;
    cin >> a;
    a = ' ' + a;
    for (int i = 1; i <= n; ++i){
        pf[i] = pf[i - 1] + (a[i] - '0');
    }
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        int l = 1, r = i, j = 1;
        while (l <= r){
            int mid = l + r >> 1;
            if (pf[i] - pf[mid - 1] >= t){
                j = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cnt += j;
    }
    cout << cnt;
    return 0;
}