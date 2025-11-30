#include<bits/stdc++.h>
#define ll long long
#define fname "posterit"

using namespace std;

const ll arr = 306, mod = 1e9 + 7;

int n, k;
ll a[arr][arr];
ll block[arr][arr][2];
ll dp[arr][arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(fname".inp","r")){
        freopen(fname".inp","r",stdin);
        freopen(fname".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 2; j <= n; ++j){
            unordered_map<ll,ll> cnt;
            cnt[a[i][j]]++;
            cnt[a[i-1][j]]++;
            cnt[a[i-1][j-1]]++;
            cnt[a[i][j-1]]++;
            if (cnt.size() >= 3) block[i][j][0] = 1, block[i][j][1] = 1;
            else {
                if (cnt.size() == 2) block[i][j][1] = 1;
            }
        }
    }
    ll cnt = 0;
    int row = 2, col = 2;
    while (row <= n){
        ll current_cnt = 0;
        for (int i = 2; i <= n; ++i){
            for (int j = 2; j <= n; ++j){
                if (i == row && j == col && block[i][j][1] == 1) current_cnt++;
                else if (block[i][j][0] == 1) current_cnt++;
            }
        }
        cnt = max(cnt, current_cnt);
        if (col == n){
            col = 2;
            row++;
        }
        col++;
    }
    cout << cnt;
}
