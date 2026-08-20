// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long
#define task "1883B"

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
        unordered_map<char, int> cnt;
        int n, k;
        string s;
        cin >> n >> k >> s;
        for (int i = 0; i < n; ++i){
            cnt[s[i]]++;
        }
        vector<ll> odds;
        for (auto i : cnt){
            if (i.second & 1) odds.push_back(i.second);
        }
        //cout << odds.size() << "\n";
        if (odds.size() <= k + 1){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}