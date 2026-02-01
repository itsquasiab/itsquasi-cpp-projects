//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string t, s;
    cin >> t >> s;
    reverse(t.begin(), t.end());
    if (t == s) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}