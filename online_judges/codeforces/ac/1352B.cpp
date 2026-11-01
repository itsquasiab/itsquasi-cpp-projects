// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1352B"

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
        ll odd = (n - k + 1);
        ll even = (n - (k - 1) * 2);
        if (odd > 0 && odd & 1){
            cout << "YES\n";
            for (int i = 1; i < k; ++i){
                cout << 1 << " ";
                n--;
            }
            cout << n << "\n";
        }
        else if (even > 0 && even % 2 == 0){
            cout << "YES\n";
            for (int i = 1; i < k; ++i){
                cout << 2 << " ";
                n -= 2;
            }
            cout << n << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}