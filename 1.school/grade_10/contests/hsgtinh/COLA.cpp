#include <bits/stdc++.h>
#define ll long long
#define tname "COLA"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n, q;
ll a[arr];
ll pl[arr], pf[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    while (q--){
        int k, m;
        cin >> k >> m;
        for (int i = 1; i <= n; ++i){
            if (a[i] <= k) pl[i] = pl[i - 1] + a[i];
            else {
                pl[i] = pl[i - 1] + k;
                pf[i] = pf[i - 1] + (a[i] - k);
            }
        }
        ll cl, cf, res = LLONG_MAX;
        for (int i = 0; i <= m; ++i){
            cl = pl[i] + pl[n] - pl[n - m + i];
            cf = pf[i] + pf[n] - pf[n - m + i];
            /*if (a[i] <= k) l += a[i];
            else {
                l += k;
                f += a[i] - k;
            }
            cl = l, cf = f;
            for (int j = n; j >= n - m + 1 + i; --j){
                if (a[j] <= k) cl += a[j];
                else {
                    cl += k;
                    cf += a[j] - k;
                }
            }*/
            res = min(res, cl - cf);
        }
        cout << res << "\n";
    }
    return 0;
}
