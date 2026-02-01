// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string s;
ll res = 0;
ll l[arr], r[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> s;
    s = " " + s;
    for (int i = 1; i < s.size(); ++i){
        if (s[i] == '<') l[i + 1] = l[i] + 1;
    }
    for (int i = s.size() - 1; i >= 1; --i){
        if (s[i] == '>') r[i] = r[i + 1] + 1;
    }
    for (int i = 1; i <= s.size(); ++i){
        res += max(l[i], r[i]);
    }
    cout << res;
    return 0;
}