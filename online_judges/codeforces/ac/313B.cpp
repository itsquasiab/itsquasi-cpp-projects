// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "313B"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll pre[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i){
        pre[i] = pre[i - 1];
        if (s[i] == s[i - 1]) pre[i]++;
    }
    int n;
    cin >> n;
    while (n--){
        int l, r;
        cin >> l >> r;
        //cout << pre[r - 1] << " " << pre[l - 1] << "\n";
        cout << pre[r - 1] - pre[l - 1] << "\n";
    }
    return 0;
}