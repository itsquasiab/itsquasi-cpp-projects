//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], dp[ARR];

ll finder(ll k){
    ll l = 1, r = k;
    while (l <= r){
        ll mid = (l + r) >> 1;
        ll t = mid * (mid + 1) >> 1;
        if (t == k) return mid;
        else if (t < k) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> kien;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (finder(a[i]) != 0) kien.push_back(a[i]);
    }
    //for (auto i : kien) cout << i << " ";
    int mx = 1;
    for (int i = 1, j = 2; j <= n; ++j){
        if (finder(a[j - 1]) != 0 && finder(a[j]) != 0){
            if (a[j - 1] > a[j]) i = j;
            mx = max(mx, j - i + 1);
        }
        else i = j;
        //cout << i << " " << j << "\n";
    }
    /*for (int i = 0; i < kien.size(); ++i){
        dp[i] = 1;
        for (int j = 0; j < i; ++j){
            if (kien[j] <= kien[i] ){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }*/
    cout << mx;
    return 0;
}