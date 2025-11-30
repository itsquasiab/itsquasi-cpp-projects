#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, k;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (k % i == 0 && k / i <= n) cnt++;
    }
    /*for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            ll mul = i * j;
            if (mul == k) cnt++;
        }
    }*/
    cout << cnt;
    return 0;
}
