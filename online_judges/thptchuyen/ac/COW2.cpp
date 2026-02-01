//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = a[n];
    ll res = 0;
    while (l <= r){
        int mid = l + r >> 1;
        int cow = 1;
        ll last = a[1];
        for (int i = 2; i <= n; ++i){
            if (a[i] - last >= mid){
                last = a[i];
                cow++;
            }
        }
        if (cow >= k){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}