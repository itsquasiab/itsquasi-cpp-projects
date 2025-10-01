#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

long long S(long long N) {
    if (N <= 0) return 0;
    long long i = 1;
    i128 res = 0;
    while (i <= N) {
        long long q = N / i;
        long long nxt = N / q + 1; // first index after current block
        long long cnt = nxt - i;
        res += (i128)q * (i128)cnt;
        i = nxt;
    }
    return (long long)res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long L, R;
    cin >> L >> R;
    if (L > R){
        cout << 0;
        return 0;
    }
    long long ans = S(R) - S(L - 1);
    cout << ans << '\n';
    return 0;
}
