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
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll div3 = n / 3;
        ll sum1 = (1 + n) * n / 2;
        ll sum2 = (3 + div3 * 3) * div3 / 2;
        cout << sum1 + sum2 << "\n";
    }
    return 0;
}
