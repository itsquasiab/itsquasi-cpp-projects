//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    bool f = 0;
    while (n--){
        ll a;
        cin >> a;
        if (a == 1) f = 1;
    }
    if (f) cout << "HARD";
    else cout << "EASY";
    return 0;
}