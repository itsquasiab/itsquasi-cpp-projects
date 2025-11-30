#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];
vector<ll> p;

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= arr; j += i) prime[j] = 1;
        }
    }
    for (int i = 2; i <= arr; ++i){
        if (!prime[i]) p.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("5prime.inp","r")){
        freopen("5prime.inp","r",stdin);
        freopen("5prime.out","w",stdout);
    }
    sieve();
    ll n;
    cin >> n;
    int t = lower_bound(p.begin(), p.end(), n) - p.begin();
    ll res = 1, cnt = 0;
    for (int i = t; i < t + 5; ++i){
        res = (res * p[i]) % mod;
    }
    cout << res;
    return 0;
}
