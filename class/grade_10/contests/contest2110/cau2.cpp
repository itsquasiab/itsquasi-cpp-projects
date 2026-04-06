#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen("cau1.inp","r")){
        freopen("cau1.inp","r",stdin);
        freopen("cau1.out","w",stdout);
    }*/
    ll n;
    cin >> n;
    while (n--){
        string a;
        cin >> a;
        unordered_map<char,ll> cnt;
        for (int i = 0; i < a.size(); ++i){
            cnt[a[i]]++;
        }
        for (auto x : cnt){
            if (x.second == 1){
                cout << x.first;
                break;
            }
        }
    }
    return 0;
}
