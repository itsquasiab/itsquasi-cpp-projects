// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "xau05"

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
    string a, b;
    cin >> a >> b;
    ll cnt1 = 0, cnt2 = 0, res = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == b[2]){
            res += cnt2;
        }
        if (a[i] == b[1]){
            cnt2 += cnt1;
        }
        if (a[i] == b[0]){
            cnt1++;
        }
    }
    cout << res;
    return 0;
}