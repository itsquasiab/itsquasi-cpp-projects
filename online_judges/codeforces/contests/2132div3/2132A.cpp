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
    int tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        string tmp, a;
        cin >> tmp;
        for (int i = 0; i < n; ++i){
            a += tmp[i];
        }
        ll m;
        cin >> m;
        string b, c;
        cin >> b >> c;
        for (int i = 0; i < m; ++i){
            if (c[i] == 'D') a = a + b[i];
            else a = b[i] + a;
        }
        cout << a << "\n";
    }
    return 0;
}