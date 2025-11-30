//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], prefix_prime[arr];
bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
    for (int i = 2; i < arr; ++i){
        prefix_prime[i] = prefix_prime[i - 1] + (!prime[i] ? 1 : 0);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    ll sum = a[k];
    ll pr = prefix_prime[k];
    for (int i = k; i <= n; ++i){
        if (a[i] - a[i - k] > sum){
            sum = a[i] - a[i - k];
            pr = prefix_prime[i] - prefix_prime[i - k];
        }
        else if (a[i] - a[i - k] == sum){
            pr = max(pr, prefix_prime[i] - prefix_prime[i - k]);
        }
    }
    cout << sum << " " << pr;
    return 0;
}