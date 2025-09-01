//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 3e5 + 6, mod = 1e9, inf = LLONG_MIN;

ll n;
ll a[arr], bit[arr], dp[arr];

void upd(int p, ll val){
    for (int i = p; i <= arr; i += i & -i){
        bit[i] = max(bit[i], val);
    }
}

ll get(int p){
    ll res = 0;
    for (int i = p; i >= 1; i -= i & -i){
        res = max(res, bit[i]);
    }
    return res;
}

unordered_map<ll, bool> exist;
vector<ll> com;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; ++i){ 
        cin >> a[i], dp[i] = 1;
        if (!exist[a[i]]){
            com.push_back(a[i]);
            exist[a[i]] = 1;
        }
    }
    sort(com.begin(), com.end());
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin() + 1;
        //cout << a[i] << " ";
    }
    for (int i = 1; i <= n; ++i){
        dp[i] = get(a[i] - 1) + 1;
        upd(a[i], dp[i]);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}