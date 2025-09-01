//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll bit[ARR], a[ARR];
int n, q;

void update(int id, ll val){
    for (int i = id; i <= n; i += i & -i){
        bit[i] += val;
    }
}

ll get(int id){
    ll res = 0;
    for (int i = id; i > 0; i -= i & -i){
        res += bit[i];
    }
    return res;
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
        else cout << get(v) - get(u - 1) << "\n";
    }
    return 0;
}