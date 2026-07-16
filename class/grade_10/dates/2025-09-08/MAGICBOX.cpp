//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 10006, mod = 1e9, inf = LLONG_MIN;

pair<ll,ll> a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= 2 * (m + n); ++i){
        cin >> a[i].second;
        a[i].first = i;
    }
    return 0;
}