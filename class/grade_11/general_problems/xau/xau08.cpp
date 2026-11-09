// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "xau08"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string a;

ll cntmost(int k){
    unordered_map<char, int> mp;
    int i = 0, j = 0, res = 0;
    while (i < a.size() && j < a.size()){
        mp[a[j]]++;
        while (mp.size() > k){
            mp[a[i]]--;
            if (mp[a[i]] == 0) mp.erase(a[i]);
            i++;
        }
        res += j - i + 1;
        j++;
    }
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
    int k;
    cin >> a >> k;
    cout << cntmost(k) - cntmost(k - 1);
    return 0;
}