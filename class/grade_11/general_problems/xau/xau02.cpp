// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "xau02"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<char, int> cnt1, cnt2;

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
    for (char c : a) cnt1[c]++;
    for (char c : b) cnt2[c]++;
    ll res = 0;
    for (char c = 'a'; c <= 'z'; ++c){
        res += abs(cnt1[c] - cnt2[c]);
    }
    cout << res;
    return 0;
}