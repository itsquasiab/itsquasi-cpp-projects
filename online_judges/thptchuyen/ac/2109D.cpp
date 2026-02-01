//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, a[arr];
int m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    ll l = 1, r = 0;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
        r = max(r, a[i]);
    }
    ll res = 0;
    while (l <= r){
        ll mid = l + r >> 1;
        int robot_used = 0;
        for (int i = 1; i <= m; ++i){
            robot_used += (a[i] + mid - 1) / mid;
        }
        if (robot_used <= n){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}