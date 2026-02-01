#include <bits/stdc++.h>
#define ll long long
#define tname "ELIS"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n;
int res = 0;
vector<ll> a;
vector<ll> b;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int u, v;
        cin >> u >> v;
        for (int j = u; j < u + v; ++j){
            a.push_back(j);
        }
    }
    //for (auto i : a) cout << i << " "; cout << "\n";
    b.resize(a.size() + 1);
    for (int i = 0; i < a.size(); ++i){
        int j = lower_bound(b.begin() + 1, b.begin() + 1 + res, a[i]) - b.begin();
        //cout << j << " ";
        b[j] = a[i];
        res = max(res, j);
    }
    cout << res;
    return 0;
}
