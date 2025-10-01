//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

map<ll,ll> cnt;

void find(ll x){
    ll c = 0;
    for (int i = 2; i <= x; ++i){
        if (x % i == 0){
            while (x % i == 0) x /= i, cnt[i]++;
        }
    }
    if (x > 1) cnt[x]++;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll sum = 1;
    while (n--){
        ll a;
        cin >> a;
        find(a);
    }
    for (auto i : cnt){
        sum *= (i.second + 1);
    }
    cout << sum;
    return 0;
}