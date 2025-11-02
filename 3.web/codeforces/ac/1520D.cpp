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
    int ts;
    cin >> ts;
    while (ts--){
        int n;
        cin >> n;
        unordered_map<ll, ll> kien;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            ll val = a[i] - i;
            kien[val]++;
        }
        ll res = 0;
        for (auto i : kien){
            ll f = i.second;
            res += f * (f - 1) / 2;
        }
        cout << res << "\n";
    }
    return 0;
}