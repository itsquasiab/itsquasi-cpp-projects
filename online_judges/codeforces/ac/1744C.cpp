// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define task "1744C"

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
        vector<ll> pos, pos_g;
        int n;
        char c;
        string a;
        cin >> n >> c >> a;
        if (c == 'g'){
            cout << 0 << "\n";
            continue;
        }
        a = (a + a);
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] == 'g')
                pos_g.push_back(i);

            if (i < n && a[i] == c)
                pos.push_back(i);
        }
        int i = 0, j = 0, res = 0;
        while (i < pos.size() && j < pos_g.size()){
            while (j < pos_g.size() && pos[i] > pos_g[j]) j++;
            if (j == pos_g.size()) break;
            int diff = abs(pos[i] - pos_g[j]);
            res = max(res, diff);
            i++;
        }
        cout << res << "\n";
    }
    return 0;
}