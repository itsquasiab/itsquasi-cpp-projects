//2025 = 45² = (20+25)² = 5²*9² = (1+2+3+4+5+6+7+8+9)² = 1³+2³+3³+4³+5³+6³+7³+8³+9³
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct kien{
    int a,b,c;
};

kien a[100005];

ll dp[100005][5];

int main()
{
    /*if (fopen(".inp","r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }*/
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    dp[0][0] = a[0].a, dp[0][1] = a[0].b, dp[0][2] = a[0].c;
    for (int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i].a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i].b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i].c;
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}
