// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
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
        cin >> n;
        vector<ll> es;
        for (int i = 2; i * i <= n; ++i){
            if (n % i == 0 && n / i != i){
                n /= i;
                es.push_back(i);
            }
            if (es.size() == 2){
                break;
            }
        }
        if (es.size() < 2) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto i : es) cout << i << " ";
            cout << n << "\n";
        }
    }
    return 0;
}