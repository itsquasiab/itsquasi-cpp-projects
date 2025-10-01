//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a;
    cin >> a;
    int t1 = a[0] - '0';
    if (t1 != 9 && 9 - t1 < t1) t1 = 9 - t1;
    a[0] = t1 + '0';
    for (int i = 1; i < a.size(); ++i){
        int t = a[i] - '0';
        if (9 - t < t) t = 9 - t;
        a[i] = t + '0';
    }
    cout << a;
    return 0;
}