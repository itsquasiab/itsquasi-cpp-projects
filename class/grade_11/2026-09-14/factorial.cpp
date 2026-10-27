#include <iostream>
#define ll long long
#define task "factorial"

using namespace std;

const ll arr = 1e6 + 6, mod = 20240131;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    ll res = 1;
    ll x = 1;
    for (ll i = 0; i < n - 1; ++i){
        x = (x * (i + 2)) % mod;
        res = (res + x) % mod;
    }
    cout << res;
    return 0;
}