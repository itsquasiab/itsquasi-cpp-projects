#include<bits/stdc++.h>
#define ll long long

using namespace std;

map<char, int> cntbase;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string a;
    ll n;
    cin >> a >> n;
    for (char i : a){
        cntbase[i]++;
    }
    ll res = 0;
    while(n--){
        string b;
        cin >> b;
        map<char, int> cnt;
        for (char c : b){
            cnt[c]++;
        }
        bool f = 1;
        for (auto x : cntbase){
            //cout << cnt[x.first] << " " << x.second << "\n";
            if (cnt[x.first] < x.second){
                f = 0;
                break;
            }
        }
        if (f) res++;
        //cout << "\n";
    }
    cout << res;
    return 0;
}
