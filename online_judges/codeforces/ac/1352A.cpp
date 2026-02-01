//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        int rd = 10;
        vector<ll> grp;
        int cnt = 0;
        while (n){
            ll num = n % rd;
            if (num != 0) grp.push_back(num), cnt++, n -= num;
            rd *= 10;
        }
        cout << cnt << "\n";
        for (auto i : grp){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}