#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, q;
ll k, a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> q;
    while(q--){
        int l, r;
        ll res = LLONG_MIN;
        cin >> l >> r;
        for (int i = l; i <= r; ++i){
            for (int j = i + 1; j <= r; ++j){
                res = max(res, a[i] * a[j]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}