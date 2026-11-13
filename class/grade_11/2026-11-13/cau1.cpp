#include <bits/stdc++.h>
#define ll long long
#define task "cau1"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n, p;
    cin >> n >> p;
    ll x = n * p * (n >= 10 ? 0.8 : 1);
    cout << x;
    return 0;
}
