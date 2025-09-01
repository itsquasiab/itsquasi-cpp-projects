//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

unordered_map<ll, bool> e;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        ll a;
        cin >> a;
        e[a] = 1;
    }
    while (n--){
        ll x;
        cin >> x;
        if (e[x] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}