//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr];
bool exist[10];
vector<ll> res;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        if (!exist[a[i]]){
            res.push_back(a[i]);
            exist[a[i]] = 1;
        }
    }
    for (auto i : res){
        cout << i << " ";
    }
    return 0;
}