// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "43A"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<string, int> mp;

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
        string a;
        cin >> a;
        mp[a]++;
    }
    string res = "";
    int mx = 0;
    for (auto i : mp){
        if (i.second > mx){
            mx = i.second;
            res = i.first;
        }
    }
    cout << res;
    return 0;
}