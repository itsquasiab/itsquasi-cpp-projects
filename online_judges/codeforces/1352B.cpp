// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1294C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        ll n;
        int k;
        cin >> n >> k;
        if (k == n) {
            cout << "YES\n";
            for (int i = 1; i <= k; ++i) cout << 1 << " ";
            cout << "\n";
        }
        else if (n & 1){
            if ((n - k + 1) % 2 == 0) cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 1; i < k; ++i){
                    cout << 1 << " ";
                }
                cout << n - k + 1 << "\n";
            }
        }
        else {
            if (n - (k - 1) * 2 <= 1) cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 1; i < k; ++i){
                    cout << 2 << " ";
                }
                cout << n - (k - 1) * 2 << "\n";
            }
        }
    }
    return 0;
}