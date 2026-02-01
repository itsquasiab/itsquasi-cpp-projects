#include<bits/stdc++.h>
#define ll long long
#define tname "order24"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
ll a[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (k == 1){
        for (int i = 1; i < n; ++i){
            if (a[i + 1] < a[i]){
                swap(a[i + 1], a[i]);
                break;
            }
        }
        for (int i = 1; i <= n; ++i){
            cout << a[i] << " ";
        }
    }
    return 0;
}

