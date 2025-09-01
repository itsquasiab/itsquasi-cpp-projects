//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0, d = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'A') a++;
        else d++;
    }
    if (a > d) cout << "Anton";
    else if (a < d) cout << "Danik";
    else cout << "Friendship";
    return 0;
}