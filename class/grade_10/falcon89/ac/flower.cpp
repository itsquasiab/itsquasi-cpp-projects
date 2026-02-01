//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], dp[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll ans = 0;
    dp[0] = 0;
    deque<ll> dq;
    dq.push_back(0);
    for (int i = 1; i <= n + 1; ++i){
        while (dq.size() && dq.front() < i - k) dq.pop_front();
        dp[i] = dp[dq.front()] + a[i];
        ans += a[i];
        while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << ans - dp[n + 1];
    return 0;
}