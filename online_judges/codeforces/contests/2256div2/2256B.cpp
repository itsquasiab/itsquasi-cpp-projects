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

        // Các biến cờ đánh dấu 4 pattern có hợp lệ hay không
        int even_pattern1 = 1, even_pattern2 = 1; // Cho các index 0, 2, 4...
        int odd_pattern1 = 1, odd_pattern2 = 1;   // Cho các index 1, 3, 5...

        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                int val = s[i] - '0';
                
                // Expected value cho mẫu đan xen 0, 1, 0, 1...
                int exp1 = (i / 2) % 2; 
                // Expected value cho mẫu đan xen 1, 0, 1, 0...
                int exp2 = 1 - exp1;    

                if (i % 2 == 0) { // Vị trí chẵn (0-indexed)
                    if (val != exp1) even_pattern1 = 0;
                    if (val != exp2) even_pattern2 = 0;
                } else {          // Vị trí lẻ (0-indexed)
                    if (val != exp1) odd_pattern1 = 0;
                    if (val != exp2) odd_pattern2 = 0;
                }
            }
        }

        // Tính toán kết quả
        long long ans = 0;
        if (n == 1) {
            ans = even_pattern1 + even_pattern2;
        } else {
            ans = 1LL * (even_pattern1 + even_pattern2) * (odd_pattern1 + odd_pattern2);
        }
        
        // In ra kết quả (Không cần modulo vì ans lớn nhất chỉ bằng 4)
        cout << ans << "\n";
    }
    return 0;
}