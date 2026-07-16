#include <bits/stdc++.h>
#define ll long long
#define task "friend"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll subarr[arr];

int main(){
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    ll b;
    cin >> n >> b;
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll res = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; ++i){
        int j = lower_bound(a + 1 + i, a + 1 + n, b - a[i]) - a;
        if (a[j] + a[i] == b){
            int j1 = upper_bound(a + 1 + i, a + 1 + n, b - a[i]) - a;
            res += j1 - j;
        }
    }
    cout << res;
    return 0;
}
