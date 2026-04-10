// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "triangle2"

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
    int n;
    cin >> n;
    while (n--){
        ll a[6];
        for (int i = 0; i < 4; ++i){
            cin >> a[i];
        }
        sort(a, a + 4);
        bool f = 0;
        for (int i = 0; i < 2; ++i){
            if (a[i] + a[i + 1] > a[i + 2]){
                cout << "TRIANGLE\n";
                f = 1;
                break;
            }
        }
        if (!f){
            for (int i = 0; i < 2; ++i){
                if (a[i] + a[i + 1] == a[i + 2]){
                    cout << "SEGMENT\n";
                    f = 1;
                    break;
                }
            }
        }
        if (!f) cout << "IMPOSSIBLE\n";
    }
    return 0;
}