//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] < '0' && a[i] > '9') a.erase(i, 1);
    }
    cout << a;
    return 0;
}