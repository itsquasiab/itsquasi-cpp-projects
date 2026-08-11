// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "2256B"

using namespace std;

const ll arr = 1e6 + 6, mod = 998244353;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        string s;
        cin >> n >> s;

        int even_pattern1 = 1, even_pattern2 = 1;
        int odd_pattern1 = 1, odd_pattern2 = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                int val = s[i] - '0';
                
                int exp1 = (i / 2) % 2; 
                int exp2 = 1 - exp1;    

                if (i % 2 == 0) {
                    if (val != exp1) even_pattern1 = 0;
                    if (val != exp2) even_pattern2 = 0;
                } else {
                    if (val != exp1) odd_pattern1 = 0;
                    if (val != exp2) odd_pattern2 = 0;
                }
            }
        }

        long long ans = 0;
        if (n == 1) {
            ans = even_pattern1 + even_pattern2;
        } else {
            ans = 1LL * (even_pattern1 + even_pattern2) * (odd_pattern1 + odd_pattern2);
        }
        cout << ans << "\n";
    }
    return 0;
}