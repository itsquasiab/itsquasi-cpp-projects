#include <bits/stdc++.h>
#define ll long long
#define task "cau3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        for (int j = i * i; j < arr; j += i){
            prime[j] = 1;
        }
    }
}

int sumdigit(int x){
    int t = 0;
    while (x){
        t += x % 10;
        x /= 10;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = n; i <= m; ++i) if (!prime[sumdigit(i)]) res++;
    cout << res;
    return 0;
}
