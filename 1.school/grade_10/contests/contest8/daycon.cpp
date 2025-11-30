//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    /*ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            if (pf[i] - pf[j - 1] == i - j + 1) cnt++;
        }
    }
    cout << cnt;*/
    ll res = 0, sum = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i){
        sum += a[i] - 1;
        res += cnt[sum];
        cnt[sum]++;
    }
    cout << res;
    return 0;
}