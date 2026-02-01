//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr];

ll fastpow(ll x, ll y){
    ll sum = 1;
    while (y){
        if (y & 1){
            sum *= x;
        }
        x *= x;
        y /= 2;
    }
    return sum;
}
vector<ll> divs;
void findivs(ll n){
    divs.push_back(1);
    divs.push_back(n);
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            divs.push_back(i);
            if (n / i != i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("uocso.inp","r"))
    {
        freopen("uocso.inp", "r", stdin);
        freopen("uocso.out", "w", stdout);
    }
    ll m, s;
    cin >> m >> s;
    unsigned ll num = 1;
    for (int i = 1; i <= m; ++i){
        ll a, b;
        cin >> a >> b;
        num *= fastpow(a, b);
    }
    findivs(num);
    for (int i = 1; i <= 3; ++i){
        ll a, b;
        cin >> a >> b;
        ll t1 = lower_bound(divs.begin(), divs.end(), a) - divs.begin();
        ll t2 = lower_bound(divs.begin(), divs.end(), b) - divs.begin();
        if (divs[t2] > b) t2--;
        cout << t2 - t1 + 1 << "\n";
    }
    return 0;
}