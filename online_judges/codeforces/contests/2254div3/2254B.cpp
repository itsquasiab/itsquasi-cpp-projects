// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "2254B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int compress(string a){
    vector<char> chars;
    chars.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i){
        if (a[i] == chars.back()) continue;
        chars.push_back(a[i]);
    }
    return chars.size();
}

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
        int n;
        string a;
        cin >> n >> a;
        int original = compress(a);
        int res = original;
        for (int i = 1; i < a.size() - 1; ++i){
            char left = a[i - 1], mid = a[i], right = a[i + 1];
            if (left != mid && mid != right && left != right) res = min(res, original - 1);
            else if (left == right && left != mid){
                res = min(res, original - 2);
            }
            else if (left == mid && mid == right) continue;
        }
        cout << res << "\n";
    }
    return 0;
}