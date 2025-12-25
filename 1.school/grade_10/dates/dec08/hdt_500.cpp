#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2006, mod = 1e9 + 7;

ll n, m, d;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n >> d;
    ll a[m + 5][n + 5];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]);
        }
    }
    /*for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/
    ll x = LLONG_MIN;
    for (int i = d; i <= m; ++i){
        for (int j = d; j <= n; ++j){
            ll block_extract = a[i][j] - a[i - d][j] - a[i][j - d] + a[i - d][j - d];
            int i1 = i - 1;
            int j1 = j;
            int nts = 1;
            while (nts < d){
                //cout << a[i1][j1] - a[i1 - 1][j1] - a[i1][j - nts] + a[i1 - 1][j1 - nts] << " ";
                block_extract -= (a[i1][j1] - a[i1 - 1][j1] - a[i1][j - nts] + a[i1 - 1][j1 - nts]);
                i1--;
                nts++;
            }
            //cout << "\n";
            x = max(x, block_extract);
        }
    }
    cout << x;
}

