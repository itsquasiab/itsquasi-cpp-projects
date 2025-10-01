//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

pair<bool,ll> a[arr];

unordered_map<ll,ll> cnt1;
unordered_map<ll,ll> cnt2;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        if (a[i].first == 1) cnt1[a[i].second]++;
        else cnt2[a[i].second]++;
    }
    cout << cnt1.size() + cnt2.size();
    return 0;
}