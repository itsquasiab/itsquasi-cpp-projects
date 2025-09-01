//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9;

ll dp[arr];
ll sum[arr];
ll a[arr] , bit[arr] , b[arr]; 
int n;
void upd(int u ,ll v)
{
    for(int i = u ;i <= arr ; i += i & (-i))
        bit[i] = max(bit[i] , v);
}
ll get(int u)
{
    ll res = 0;
    for(int i = u ;i >= 1 ; i -= i & (-i))
        res = max(res , bit[i]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   
    cin >> n;
    for(int i = 1;i <= n; ++i) cin >> a[i] , dp[i] = 0;
    for(int i = 1;i <= n ;++ i) cin >> b[i];
    ll res = 0;
    for(int i = 1;i <= n; ++i){
            dp[i] = get(a[i] - 1) + b[i];
            upd(a[i] , dp[i]);
            res = max(res , dp[i]);
    }
    cout << res;
}