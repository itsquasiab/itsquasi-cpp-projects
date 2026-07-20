// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "lc_ts10_24_d"

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
    string a;
    ll k;
    cin >> a >> k;
    bool same_char = 1;
    for (int i = 1; i < a.size(); ++i){
        if (a[0] != a[i]){
            same_char = 0;
            break;
        }
    }
    if (same_char) cout << (a.size() * k) / 2;
    else {
        vector<int> strsz;
        int cnt = 1;
        for (int i = 1; i < a.size(); ++i){
            if (a[i] != a[i - 1]) strsz.push_back(cnt), cnt = 1;
            else cnt++;
        }
        strsz.push_back(cnt);
        int pf = strsz.front();
        int sf = strsz.back();
        ll res = 0;
        for (int i = 1; i < strsz.size() - 1; ++i){
            res += strsz[i] / 2 * k;
        }
        if (a[0] == a[a.size() - 1]) res += (pf / 2) + (sf / 2) + (k - 1) * ((pf + sf) / 2);
        else res += k * (pf / 2) + k * (sf / 2);
        cout << res << "\n";
    }
    return 0;
}
