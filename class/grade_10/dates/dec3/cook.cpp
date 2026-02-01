#include<iostream>
#define ll long long
#define tname "cook"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k, m;
ll a[arr];
ll dp[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int t = 0;
    for (int i = 1; i <= n; ++i){

    }
    cout << t;
    return 0;
}

