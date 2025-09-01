//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll bit[ARR], a[ARR];
int n, q;

void update(int u, int v){
    int idx = u;
    while(idx <= n){
        bit[idx] += v;
        idx += idx & -idx;
    }
}

ll sum(int p){
    int idx = p;
    ll ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--){
        ll l, u, v;
        cin >> l >> u >> v;
        if (l == 1){
            update(u, v - a[u]);
            a[u] = v;
        }
        else cout << sum(v) - sum(u - 1) << "\n";
    }
    return 0;
}