// Minding my own business. :)
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string num;
ll dp[20][20][2][2]; // dp[pos][cnt][isZero][tight]
ll a, b;
int d1, k;

ll solver(int pos, int cnt, bool isZero, bool tight) {
    if (pos == (int)num.size())
        return (!isZero && cnt == k);

    ll &res = dp[pos][cnt][isZero][tight];
    if (res != -1) return res;
    res = 0;

    int limit = tight ? (num[pos] - '0') : 9;

    for (int d = 0; d <= limit; ++d) {
        bool new_tight = tight && (d == limit);
        bool new_isZero = isZero && (d == 0);
        int new_cnt = cnt;

        // nếu đã bắt đầu số (tức là !new_isZero)
        // thì mới được tính chữ số d1
        if (d == d1 && !new_isZero)
            new_cnt++;

        res += solver(pos + 1, new_cnt, new_isZero, new_tight);
    }

    return res;
}

ll count_to(ll n) {
    if (n < 0) return 0;
    num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> d1 >> k;
    cout << count_to(b) - count_to(a - 1) << '\n';
    return 0;
}