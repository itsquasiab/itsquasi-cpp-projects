#include <bits/stdc++.h>
#define ll long long
#define tname "DMORY"

using namespace std;

const ll arr = 5e5 + 6, mod = 1e9 + 7;

int n;
ll a[arr], res = 0, k;
deque<ll> mna, mxa;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int l = 1, r = 1;
    while (r <= n){
        while(!mna.empty() && a[mna.back()] >= a[r]) mna.pop_back();
        while(!mxa.empty() && a[mxa.back()] <= a[r]) mxa.pop_back();
        mna.push_back(r);
        mxa.push_back(r);
        while (a[mxa.front()] - a[mna.front()] > k){
            if (l == mxa.front()) mxa.pop_front();
            if (l == mna.front()) mna.pop_front();
            l++;
        }
        res += r - l + 1;
        cout << l << " " << r << "\n";
        r++;
    }
    cout << res;
    return 0;
}
