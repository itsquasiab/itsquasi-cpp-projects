// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "2254C2"

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
            cout << "0\n";
            continue;
        }
        if (a != b && n < 2){
            cout << "-1\n";
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
            vector<ll> a1, a2, b1, b2;
            for (int i = 0; i < n; ++i){
                if (a[i] == '1'){
                    if (i & 1) a2.push_back(i);
                    else a1.push_back(i);
                }
                if (b[i] == '1'){
                    if (i & 1) b2.push_back(i);
                    else b1.push_back(i);
                }
            }
            ll res = 0;
            for (int i = 0; i < a2.size(); ++i){
                res += abs(a2[i] - b2[i]) / 2;
            }
            for (int i = 0; i < a1.size(); ++i){
                res += abs(a1[i] - b1[i]) / 2;
            }
            cout << res << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}