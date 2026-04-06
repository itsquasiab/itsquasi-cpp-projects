//MADE BY ITSQUASI
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll arr = 1e6+6, mod = 1e9+7;

ll a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("hoatiet.inp", "r")){
        freopen("hoatiet.inp", "r", stdin);
        freopen("hoatiet.out", "w", stdout);
    }
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    return 0;
}
