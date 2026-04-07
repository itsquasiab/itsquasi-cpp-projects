// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "angry"

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
        int n, k;
        cin >> n >> k;
        ll right_time = 0;
        while (n--){
            ll a;
            cin >> a;
            if (a <= 0) right_time++;
        }
        if (right_time < k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}