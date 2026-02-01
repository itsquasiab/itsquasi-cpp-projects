//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

int n;
ll w;
pair<ll,ll> a[arr];
ll dp[arr], choice[arr], cnt[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = a[i].first; j <= w; ++j){
            if (dp[j] < dp[j - a[i].first] + a[i].second) {
                dp[j] = dp[j - a[i].first] + a[i].second;
                choice[j] = i;
            }
        }
    }
    cout << dp[w] << "\n";
    int w1 = w;
    while (w1 > 0 && choice[w1] != 0) {
        int i = choice[w1];
        cnt[i]++;
        w1 -= a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 0)
            cout << i << " " << cnt[i] << "\n";
    }
    return 0;
}