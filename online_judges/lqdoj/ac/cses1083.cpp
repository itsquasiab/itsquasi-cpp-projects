//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

map<ll,bool> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        ll a;
        cin >> a;
        cnt[a] = 1;
    }
    for (int i = 1; i <= n; ++i){
        if (cnt[i] == 0){
            cout << i;
            break;
        }
    }
    return 0;
}