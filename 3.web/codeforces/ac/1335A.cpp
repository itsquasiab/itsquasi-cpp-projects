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
        if (n <= 2) cout << 0;
        else {
            cout << (n - 1) / 2;
        }
        cout << "\n";
    }
    return 0;
}