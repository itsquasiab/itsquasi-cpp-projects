// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "1914D"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

vector<int> best3 (vector<ll> a){
    ll mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < a.size(); ++i){
        if (mx1 == -1 || a[i] > a[mx1]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if (mx2 == -1 || a[i] > a[mx2]){
            mx3 = mx2;
            mx2 = i;
        }
        else if (mx3 == -1 || a[i] > a[mx3]){
            mx3 = i;
        }
    }
    vector<int> res;
    res.push_back(mx1);
    res.push_back(mx2);
    res.push_back(mx3);
    return res;
}

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
        vector<ll> a, b, c;
        ll x;
        for (int i = 1; i <= n; ++i) cin >> x, a.push_back(x);
        for (int i = 1; i <= n; ++i) cin >> x, b.push_back(x);
        for (int i = 1; i <= n; ++i) cin >> x, c.push_back(x);
        ll res = 0;
        vector<int> g1 = best3(a), g2 = best3(b), g3 = best3(c);
        for (int x : g1){
            for (int y : g2){
                for (int z : g3){
                    if (x != y && x != z && y != z){
                        res = max(res, a[x] + b[y] + c[z]);
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}