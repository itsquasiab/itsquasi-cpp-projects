//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll n, k, a[arr];
unordered_map<ll,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cnt.reserve(arr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cnt[0] = 1;
    ll sum = 0;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        sum += a[i];
        sum = (sum % k + k) % k;
        res += cnt[sum];
        cnt[sum]++;
        //cout << sum << " ";
    }
    cout << res;
    return 0;
}