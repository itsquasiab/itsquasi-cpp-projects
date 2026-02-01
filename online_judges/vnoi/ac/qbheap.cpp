//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

multiset<ll, greater<ll>> kien;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    char s;
    while(cin >> s){
        if (s == '-' && !kien.empty()){
            ll v = *kien.begin();
            while(!kien.empty() && *kien.begin() == v) kien.erase(kien.begin());
        }
        else if (s == '+'){
            ll v;
            cin >> v;
            if (kien.size() < 15000)
            kien.insert(v);
            //cout << t << " ";
        }
        /*for (auto i : kien) cout << i << " ";
        cout << "\n";*/
    }
    vector<ll> out;
    ll last = LLONG_MIN;
    for (ll x : kien) {
        if (x != last) {
            out.push_back(x);
            last = x;
        }
    }

    cout << out.size() << '\n';
    for (ll x : out) cout << x << '\n';
    return 0;
}