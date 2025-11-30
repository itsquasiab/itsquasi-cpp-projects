#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fol(i, x, y, z) for (int i = x; i <= y; i += z)
#define foq(i, x, y, z) for (int i = x; i >= y; i -= z)
#define sync()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define se second
#define fi first
int mod = 1e9 + 7;
int n, m, d, k;
int dp[30][30][30][3];
main()
{
    sync();
    auto solve = [&](auto &&self, int idx, int tight, int len, int zero, vector<int> &a) -> int
    {
        if (idx == a.size())
            return (len == k);
        if (dp[idx][tight][len][zero] != -1)
            return dp[idx][tight][len][zero];
        int limit = tight ? a[idx] : 9;
        int res = 0;
        fol(i, 0, limit, 1)
        {
            int them = !(zero and (i == 0)) and (i == d);
            int nzero = zero and (i == 0);
            int ntight = (tight and (i == limit));
            res += self(self, idx + 1, ntight, len + them, nzero, a);
        }
        dp[idx][tight][len][zero] = res;
        return res;
    };
    auto pt = [&](int x)
    {
        vector<int> a;
        string s = to_string(x);
        for (char i : s)
            a.push_back(i - '0');
        memset(dp, -1, sizeof dp);
        return solve(solve, 0, 1, 0, 1, a);
    };
    cin >> n >> m >> d >> k;
    cout << pt(m) - pt(n - 1);
}
/*
*leading zero
vấn đề xảy ra khi nếu chọn 0 ở những vị trí đầu tiên thì coi như đó là 1 chữ số thực sự
ex : 00057 vẫn được coi là k lần chữ số d kể cả khi tất cả đều là 0
điều này gây ra lỗi đếm số khi những số 0 không phải là số 0 thực sự lại được đếm, gây ra kết quả lớn bất thường
*/