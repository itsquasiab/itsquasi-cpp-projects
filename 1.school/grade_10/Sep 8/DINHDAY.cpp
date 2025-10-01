//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<ll> s;
    for (int i = 2; i < n; ++i){
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) s.push_back(a[i]);
    }
    cout << s.size() << "\n";
    for (auto i : s){
        cout << i << " ";
    }
    return 0;
}