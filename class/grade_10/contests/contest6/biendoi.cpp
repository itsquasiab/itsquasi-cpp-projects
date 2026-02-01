//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr];

bool prime[arr];
vector<ll> p;

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i < arr; ++i){
        if (!prime[i]) p.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("biendoi.inp","r"))
    {
        freopen("biendoi.inp", "r", stdin);
        freopen("biendoi.out", "w", stdout);
    }
    sieve();
    ll n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        
        int t = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
        ll s1 = abs(p[t] - a[i]), s2 = p[t];
        if (t > 0) s2 = abs(p[t - 1] - a[i]);
        a[i] = min(s1, s2);
        //cout << a[i] << " ";
    }
    ll sum = 0, res = LLONG_MAX;
    for (int i = 1, j = 1; j <= n; ++j){
        sum += a[j];
        while (j - i + 1 >= s){
            res = min(res, sum);
            sum -= a[i];
            i++;
        }
    }
    cout << res;
    return 0;
}