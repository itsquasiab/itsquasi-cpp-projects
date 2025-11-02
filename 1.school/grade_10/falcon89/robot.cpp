//Minding my own business. :)
//MADE BY ITSQUASI
//not done yet, i'm just gonna send it to my laptop and continue with this
//update, it's done
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr1 = 21, arr2 = 1e6 + 6;

int n;
ll a[22], b[22][22];
ll dp[1 << 20][22];
ll sum = 0, res = 0;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> b[i][j];
        }
    }

    for (int mask = 1; mask < (1 << n); ++mask){
        for (int i = 1; i <= n; ++i){
            dp[mask][i] = LLONG_MIN;
        }
    }

    for (int i = 1; i <= n; ++i)
        dp[1 << (i - 1)][i] = 0;

    for (int mask = 0; mask < (1 << n); ++mask){
        for (int i = 1; i <= n; ++i){
            if (!(mask & (1 << (i - 1)))) continue;
            for (int j = 1; j <= n; ++j){
                if (mask & (1 << (j - 1))) continue;
                int new_mask = mask | (1 << (j - 1));
                dp[new_mask][j] = max(dp[new_mask][j], dp[mask][i] + b[j][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        res = max(res, dp[(1 << n) - 1][i]);
        //cout << res << "\n";
    }
    cout << sum - res;
    /*
    3
    8 4 5
    0 1 1
    3 0 1
    2 4 0
    */
    return 0;
}