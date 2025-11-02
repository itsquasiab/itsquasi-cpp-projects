#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, X;
    cin >> n >> X;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp1(n+1), dp2(n+1), dp3(n+1);
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        dp1[i] = max(a[i], dp1[i-1] + a[i]);
        dp2[i] = max({ a[i] * X, dp1[i-1] + a[i] * X, dp2[i-1] + a[i] * X });
        dp3[i] = max({ a[i], dp2[i-1] + a[i], dp3[i-1] + a[i] });
        ans = max({ ans, dp1[i], dp2[i], dp3[i] });
    }
    cout << ans;
}