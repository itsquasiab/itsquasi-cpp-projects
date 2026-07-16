#include<iostream>
#include<algorithm>
#define ll long long
#define task "candy"

using namespace std;

const ll arr = 2e5 + 6;

int m, t;

ll d[arr], n[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> m >> t;
    for (int i = 1; i <= m; ++i) cin >> d[i];
    sort(d + 1, d + 1 + m);
    for (int i = 1; i <= m; ++i){
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= t; ++i) cin >> n[i];
    for (int i = 1; i <= t; ++i){
        ll dv1 = n[i] / m;
        ll dv2 = n[i] % m;
        if (dv2 == 0) cout << 0 << " ";
        else cout << d[m - dv2] * dv2 << " ";
        //cout << dv1 << " " << dv2 << "\n";
    }
    return 0;
}
