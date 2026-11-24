// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define ll long long
#define task "bbkg"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool isvowel(char c){
    return (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i');
}

unordered_map<char, int> cnt;
unordered_map<char, vector<int>> pos;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int type;
    string s;
    cin >> type >> s;
    if (type == 2){
        for (int i = 0; i < s.size(); ++i){
            if (isvowel(s[i])){
                s.erase(i, 1);
                i--;
            }
        }
    }
    int n = s.size();
    s = " " + s;
    /*vector<array<int, 26>> pref(n + 1);
    for (char c = 'a'; c <= 'z'; ++c){
        pref[0][c - 'a'] = 0;
    }
    for (int i = 1; i <= n; ++i){
        pref[i] = pref[i - 1];
        pref[i][s[i] - 'a']++;
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (s[i] != s[j]){
                int k = pref[n][s[i] - 'a'] - pref[j][s[i] - 'a'];
                res += k;
            }
        }
    }*/
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        if (!cnt.count(s[i])){
            cnt[s[i]]++;
            pos[s[i]].push_back(i);
        }
        else{
            int increment = 0;
            for (auto j : pos[s[i]]){
                res += (i - j - (cnt[s[i]] - increment));
                increment++;
                //cout << i - j - (cnt[s[i]] - increment) << " " << j << " " << cnt[s[i]] << " " << i << "\n";
            }
            //cout << res << "\n";
            cnt[s[i]]++;
            pos[s[i]].push_back(i);
        }
    }
    cout << res;
    return 0;
}