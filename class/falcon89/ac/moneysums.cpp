//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[1000006];
bool dp[1000006];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx += a[i];
    }
    dp[0] = 1;
    int res = 0;
    for(int i = 1;i <= n; ++i){
        for(int j = mx ; j >= a[i] ; --j){
            if(dp[j - a[i]]) dp[j] = 1;
        }
    }
    for(int i = 1;i <= mx; ++i) if(dp[i]) res++;
    cout << res << '\n';
    for(int i = 1;i <= mx ; ++i)
        if(dp[i]) cout << i << " ";
    return 0;
}