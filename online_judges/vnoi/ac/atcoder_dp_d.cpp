//2025 = 45² = (20+25)² = 5²*9² = (1+2+3+4+5+6+7+8+9)² = 1³+2³+3³+4³+5³+6³+7³+8³+9³
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct kien{
    ll v, w;
};

kien a[105];

ll dp[100005];

int main()
{
    /*if (fopen(".inp","r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }*/
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].v;

    for (int i = 1; i <= n; ++i){
        for (int j = w; j >= a[i].w; --j){
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
        }
    }
    cout << dp[w];
    return 0;
}
