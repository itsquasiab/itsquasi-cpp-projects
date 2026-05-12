// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#include <algorithm>
#define ll long long
#define task "incarr"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];
unordered_map<ll, bool> exist;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        exist[a[i]] = 1;
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    ll res = n;
    for (int i = 2; i <= n; ++i){
        if (a[i] == a[i - 1]) res--;
    }
    for (int i = 1; i <= m; ++i){
        if (!exist.count(b[i])){
            //cout << b[i] << " didn't exist\n"; 
            res++;
            exist[b[i]] = 1;
        }
    }
    cout << res;
    return 0;
}