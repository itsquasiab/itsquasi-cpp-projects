//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            a.push_back(i * j);
        }
    }
    sort (a.begin(), a.end());
    cout << a[k - 1];
    return 0;
}