// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "diffsstr"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
string a;
int res = 0;

ll hashes(string s){
    ll hash = 0;
    for (int i = 0; i < s.size(); ++i){
        hash = (hash * 31 + (s[i] - 'A' + 1)) % mod;
    }
    return hash;
}

bool check(int l){
    unordered_map<ll, bool> seen;
    //cout << l << " ";
    for (int i = 1; i <= n - l + 1; ++i){
        string p = a.substr(i, l);
        ll hashp = hashes(p);
        //cout << hashp << " ";
        if (seen[hashp] == 1) return 0;
        seen[hashp] = 1;
    }
    //cout << "\n";
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> a;
    a = " " + a;
    int l = 1, r = n;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}