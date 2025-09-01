//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], bit[ARR];
int n, q;

void update(int i, ll val){
    int idx = i;
    while (idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll sum(int i){
    int idx = i;
    ll ans = 0;
    while (idx > 0){
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    while (q--){
        char l;
        ll u, v;
        cin >> l >> u >> v;
        if (l == 'S'){ 
            ll dif = v - a[u];
            a[u] = v;
            update(u, dif);
        }
        else cout << sum(v) - sum(u - 1) << "\n"; 
    }
    return 0;
}