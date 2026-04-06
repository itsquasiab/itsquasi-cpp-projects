#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll n, t;

ll solve(ll n){
    if (n == 0) return 0;
    ll res = 0, d = 1;
    while (d <= n){
        ll d1 = n / (n / d);
        res += (n / d) * (d1 - d + 1);
        d = d1 + 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> t;
    cout << solve(t) - solve(n - 1);
    return 0;
}
