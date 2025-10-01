//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

unordered_map<string, ll> cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        string a;
        cin >> a;
        if (!cnt[a]) cout << "OK\n";
        else cout << a << cnt[a] << "\n";
        cnt[a]++;
    }
    return 0;
}