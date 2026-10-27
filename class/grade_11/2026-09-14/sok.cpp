#include <iostream>
#include <algorithm>
#define ll long long
#define task "sok"

using namespace std;

const ll arr = 1e5 + 6, mod = 20240131;

ll a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    while (t--){
        ll k;
        cin >> k;
        int j = 1;
        for (ll i = 1; i <= k; ++i){
            while (a[j] == i){
                k++;
                j++;
            }
        }
        cout << k << "\n";
    }
    return 0;
}