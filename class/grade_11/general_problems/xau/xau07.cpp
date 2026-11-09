// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "xau07"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<char, int> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a;
    int k;
    cin >> a >> k;
    int i = 0, j = 0, res = 0;
    while (i < a.size() && j < a.size()){
        mp[a[j]]++;
        while (mp.size() > k){
            mp[a[i]]--;
            if (mp[a[i]] == 0) mp.erase(a[i]);
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    cout << res;
    return 0;
}