//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll pf[arr], a[arr];
unordered_map<ll,ll> cnt;
int n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    cnt[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        ans += cnt[pf[i] - i];
        cnt[pf[i] - i]++;
    }
    cout << ans;
    return 0;
}