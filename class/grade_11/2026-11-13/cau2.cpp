#include <bits/stdc++.h>
#define ll long long
#define task "cau2"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    bool si = 0, up = 0, lo = 0, nu = 0;
    if (s.size() >= 8) si = 1;
    for (int i = 0; i < s.size(); ++i){
        if (isupper(s[i])) up = 1;
        else if (islower(s[i])) lo = 1;
        else if (s[i] >= '0' && s[i] <= '9') nu = 1;
    }
    if (si && up && lo && nu) cout << "STRONG";
    else cout << "WEAK";
    return 0;
}
