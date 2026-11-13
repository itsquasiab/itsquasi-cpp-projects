#include <bits/stdc++.h>
#define ll long long
#define task "cau3"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr];
int t, m, n, k;
ll res = 0;

bool blm[arr], bln[arr];

void backtrack(int pos, ll sum){
    if (pos >= k){
        res = max(res, sum);
        return;
    }
    for (int i = 1; i <= m; ++i){
        if (blm[i]) continue;
        for (int j = 1; j <= n; ++j){
            if (bln[j]) continue;
            blm[i] = 1;
            bln[j] = 1;
            backtrack(pos + 1, sum + a[i][j]);
            blm[i] = 0;
            bln[j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t >> m >> n >> k;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    if (t == 1){
        vector<ll> mnx;
        ll res = 0;
        for (int i = 1; i <= m; ++i){
            ll mx = 0;
            for (int j = 1; j <= n; ++j){
                mx = max(mx, a[i][j]);
            }
            mnx.push_back(mx);
        }
        sort (mnx.begin(), mnx.end(), greater<ll>());
        for (int i = 0; i < k; ++i) res += mnx[i];
        cout << res;
    }
    else {
        backtrack(0, 0);
        cout << res;
    }
    return 0;
}
