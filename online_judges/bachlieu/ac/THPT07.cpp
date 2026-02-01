//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll k = 0, d = 0, n, sum = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 1000000; ++i){
        sum += i;
        k = i;
        if (sum + i >= n) break;
    }
    d = n - k * (k + 1) / 2;
    if (d != 0) k++;
    ll res = 1;
    for (int i = 2; i <= k - 1; ++i){
        ll c = res % i;
        res += (i - c) + (i - 1) * i;
    }
    if (d == 0) d = k;
    ll c = res % k;
    res += (k - c) + (d - 1) * k;
    cout << res;
    return 0;
}