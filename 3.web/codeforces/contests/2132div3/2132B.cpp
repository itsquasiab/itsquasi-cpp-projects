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
        vector<ll> a;
        ll p = 10;
        for (int i = 1; i <= 18; ++i){
            ll y = p + 1;
            if(n % y == 0) a.push_back(n/y);
            if(y > n || y > LLONG_MAX / 10) break;
            p *= 10;
        }
        if (a.size() == 0) cout << 0;
        else{
        cout << a.size() << "\n";
        sort(a.begin(), a.end());
        for (auto i : a){
            cout << i << " ";
        }
        }
        cout << "\n";
    }
    return 0;
}