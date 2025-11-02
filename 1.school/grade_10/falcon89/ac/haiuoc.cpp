//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2e6 + 6, mod = 1e9, inf = LLONG_MIN;

bool prime[arr];
vector<ll> p;

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
    for (int i = 2; i < arr; ++i){
        if (!prime[i]) p.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    int n;
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        int t = lower_bound(p.begin(), p.end(), a) - p.begin();
        if (p[t] > a) cout << p[t - 1] << " ";
        else cout << a << " "; 
    }
    return 0;
}