#include <bits/stdc++.h>
#define ll long long
#define task "cau5"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
int n, k;

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
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int i = 1, j = 1;
    int cnt = 0, res = 0;
    while (i <= n && j <= n){
        if (!prime[a[j]]) cnt++;
        while (cnt >= k){
            res++;
            if (!prime[a[i]]) cnt--;
            i++;
        }
        j++;
    }
    cout << res;
    return 0;
}
