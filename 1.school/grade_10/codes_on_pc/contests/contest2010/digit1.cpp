//MADE BY ITSQUASI
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll arr = 1e6+6, mod = 1e9+7;

string num;
ll dp[10][10][2]; //dp[pos][cnt][flag]

ll solver(int pos, int cnt, bool flag){
    if (pos == num.size()) return cnt;
    if (dp[pos][cnt][flag] != -1) return dp[pos][cnt][flag];
    int limit = flag ? (num[pos] - '0') : 9;
    ll res = 0;
    for (int d = 0; d <= limit; ++d){
        bool new_flag = flag && d == limit;
        int new_cnt = cnt + (d == 1);
        res += solver(pos + 1, new_cnt, new_flag);
    }
    return dp[pos][cnt][flag] = res;
}

ll cnt(ll n){
    num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("digit1.inp", "r")){
        freopen("digit1.inp", "r", stdin);
        freopen("digit1.out", "w", stdout);
    }
    ll n;
    cin >> n;
    cout << cnt(n);
    return 0;
}
