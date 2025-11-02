//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

struct kien{
    ll x, y;
    char s;
} a[arr];

map<ll, vector<kien>> mp;

bool sorter(kien a, kien b){
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i < s.size(); ++i){
        a[i].s = s[i];
    }
    for (auto c : a){
        mp[c.y].push_back(c);
    }
    ll cnt = 0;
    for (auto r : mp){
        auto v = r.second;
        sort (v.begin(), v.end(), sorter);

        ll cntr = 0;
        for (auto c : v){
            if (c.s == 'R') cntr++;
            else cnt += cntr;
        }
    }
    cout << cnt * 3 << "\n";
    return 0;
}