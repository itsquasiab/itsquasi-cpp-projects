// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#include <set>
#define ll long long
#define task "xau06"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

set<char> distinct;
unordered_map<char, int> chars;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a;
    cin >> a;
    for (auto c : a) distinct.insert(c);
    int i = 0, j = 0;
    int res = 1e8;
    while (j < a.size()){
        chars[a[j]]++;
        while (chars.size() == distinct.size()){
            res = min(res, j - i + 1);
            chars[a[i]]--;
            if (chars[a[i]] == 0) chars.erase(a[i]);
            i++;
        }
        j++;
    }
    cout << res;
    return 0;
}