//temp:
//MADE BY ITSQUASI
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll arr = 1e6+6, mod = 1e9+7;

ll m, k;

ll finder(ll n){
    vector<string> kien;
    for (int i = 1; i <= n; ++i){
        kien.push_back(to_string(i));
    }
    sort (kien.begin(), kien.end());
    for (int i = 0; i < kien.size(); ++i){
        ll num = stoll(kien[i]);
        //cout << i << " ";
        if (num == k){
            //cout << "\n";
            return i + 1;
        }
    }
    return 0;
}

void solve(){
    ll l = 1, r = 1e5, res = 1;
    while (l <= r){
        ll mid = l + r >> 1;
        ll finding = finder(mid);
        if (finding == m){
            res = mid;
            break;
        }
        else if (finding > m){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("amusing.inp", "r")){
        freopen("amusing.inp", "r", stdin);
        freopen("amusing.out", "w", stdout);
    }
    cin >> m >> k;
    solve();
    return 0;
}
