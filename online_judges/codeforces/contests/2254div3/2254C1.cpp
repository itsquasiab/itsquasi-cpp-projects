// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "2254C1"

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
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a == b){
            cout << "YES\n";
            continue;
        }
        if (a != b && n < 2){
            cout << "NO\n";
            continue;
        }
        int odd_a = 0, even_a = 0, odd_b = 0, even_b = 0;
        for (int i = 0; i < n; ++i){
            if (a[i] == '1'){
                if (i & 1) odd_a++;
                else even_a++;
            }
            if (b[i] == '1'){
                if (i & 1) odd_b++;
                else even_b++;
            }
        }
        if (odd_a == odd_b && even_a == even_b){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}