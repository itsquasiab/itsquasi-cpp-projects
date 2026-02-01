#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 5e5 + 6;

ll a[arr];

int main(){
    if (fopen("FLOWER.inp","r")){
        freopen("FLOWER.inp","r",stdin);
        freopen("FLOWER.out","w",stdout);
    }
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] *= 2;
    }
    ll res_so_far = a[1];
    ll res_current = a[1];
    for (int i = 2; i <= n; ++i){
        res_so_far = max({
            a[i],
            res_so_far + a[i],
            });
        res_current = max(res_current, res_so_far);
    }
    cout << max(res_current, 0ll);
}
