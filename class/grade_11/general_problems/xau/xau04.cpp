// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define task "xau04"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

stack<char> str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    int k;
    cin >> s >> k;
    str.push(0);
    for (int i = 1; i < s.size(); ++i){
        while (str.size() && k && s[str.top()] > s[i]){
            str.pop();
            k--;
        }
        str.push(i);
    }
    while (str.size() && k){
        str.pop();
        k--;
    }
    vector<char> res;
    while (str.size()){
        res.push_back(s[str.top()]);
        str.pop();
    }
    for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
    return 0;
}