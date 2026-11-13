#include <bits/stdc++.h>
#define ll long long
#define task "cau4"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        for (int j = i * i; j < arr; j += i){
            prime[j] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    int n, k;
    ll s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int i = 1, j = 1, cnt = 0, res = 1e6;
    ll sum = 0;
    bool f = 0;
    while (i <= n && j <= n){
        sum += a[j];
        if (!prime[a[j]]) cnt++;
        while (sum >= s && cnt >= k){
            res = min(res, j - i + 1);
            f = 1;
            sum -= a[i];
            if (!prime[a[i]]) cnt--;
            i++;
        }
        //cout << i << " " << j << " " << sum << " " << cnt << "\n";
        j++;
    }
    cout << (f ? res : -1);
    return 0;
}

