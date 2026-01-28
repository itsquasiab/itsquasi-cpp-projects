// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr], st[22][arr];

void preMin(){
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= 20; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
void preSum(){
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= 20; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
}
int queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int querySum(int l, int r) {
    int len = r - l + 1;
    int sum = 0;
    for (int j = 0; (1 << j) <= len; ++j)
        if (len >> j & 1) {
            sum = sum + st[j][l];
            l = l + (1 << j);
        }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    return 0;
}