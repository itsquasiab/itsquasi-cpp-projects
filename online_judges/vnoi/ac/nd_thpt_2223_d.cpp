//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

bool prime[arr];
vector<ll> def;

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
}

void precompute(){
    for (int i = 2; i < arr && 1ll * i * i <= 1e10; ++i){
        if (!prime[i]) def.push_back(1ll * i * i);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("SDB.inp","r"))
    {
        freopen("SDB.inp", "r", stdin);
        freopen("SDB.out", "w", stdout);
    }
    sieve();
    precompute();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        int t = lower_bound(def.begin(), def.end(), a) - def.begin();
        cout << def[t] << " ";
    }
    return 0;
}