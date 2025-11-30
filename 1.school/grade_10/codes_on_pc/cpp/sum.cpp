#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll f[4000][4000];
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) f[1][i] = 1;
    for (int j = 1; j <= n; ++j){
        for (int i = 2; i <= sqrt(2 * j); ++i){
            f[i][j] = (f[i - 1][j - i] + f[i][j - i]) % mod;
        }
    }
    ll res = 0;
    for (int i = 2; i <= sqrt(2 * n); ++i){
        res = (res + f[i][n]) % mod;
    }
    cout << res;
    return 0;
}
