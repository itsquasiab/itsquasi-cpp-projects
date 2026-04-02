// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <map>
#include <string>
#define ll long long
#define task "cau2a"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

map<char, int> cnt;

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
    for (char c : a){
        cnt[c]++;
    }
    cout << cnt.size() << "\n";
    for (auto i : cnt){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}