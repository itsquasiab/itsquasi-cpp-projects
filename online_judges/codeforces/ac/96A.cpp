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
    string a;
    cin >> a;
    int z = 0, o = 0;
    bool f = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == '1') o++, z = 0;
        else z++, o = 0;
        if (o == 7 || z == 7){
            f = 1;
            break;
        }
    }
    cout << (f ? "YES" : "NO");
    return 0;
}