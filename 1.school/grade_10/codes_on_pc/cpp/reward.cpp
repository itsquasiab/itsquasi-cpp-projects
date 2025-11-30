#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

bool prime[arr];
ll prefix_prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
    for (int i = 2; i < arr; ++i){
        prefix_prime[i] = prefix_prime[i - 1] + (!prime[i]);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("reward.inp", "r")){
    freopen("reward.inp", "r", stdin);
    freopen("reward.out", "w", stdout);
    }
    sieve();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll sum = 0;
    ll pr_prefix = 0;
    for (int i = 1; i <= k; ++i){
        sum += a[i];
    }
    pr_prefix = prefix_prime[k];
    for (int i = k + 1; i <= n - k + 1; ++i){
        ll temp = sum + a[i] - a[i - k];
        if (temp > sum){
            sum = temp;
            pr_prefix = prefix_prime[i] - prefix_prime[i - k];
        }
        else if (temp == sum){
            pr_prefix = max(pr_prefix, prefix_prime[i] - prefix_prime[i - k]);
        }
    }
    cout << sum << " " << pr_prefix;
    return 0;
}
