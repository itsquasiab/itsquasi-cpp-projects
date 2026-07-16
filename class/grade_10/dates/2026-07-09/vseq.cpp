#include<iostream>
#define ll long long
#define task "vseq"

using namespace std;

const ll arr = 2e5 + 6;

int n, q;
ll m;

ll a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--){
        int type;
        cin >> type;
        if (type == 1){
            int l, r;
            ll c;
            cin >> l >> r >> c;
            for (int i = l; i <= r; ++i){
                a[i] = (a[i] + c) % m;
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            int base = a[l];
            bool found = 0;
            for (int i = l + 1; i <= r; ++i){
                if (a[i] != base){
                    found = 1;
                    break;
                }
            }
            cout << found << "\n";
        }
    }
    return 0;
}
