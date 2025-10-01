//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pf[arr];

unordered_map<ll,ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cnt[0] = 1;
    ll sum = 0;
    ll num = 0;
    for (int i = 1; i <= n; ++i){
        sum = (sum + a[i]) % t;
        num += cnt[sum];
        cnt[sum]++;
    }
    cout << num;
    return 0;
}