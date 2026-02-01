//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];
bool dp[arr];
vector<ll> order;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= n; ++j){
        for (int i = sum; i >= a[j]; --i){
            if (dp[i - a[j]] == 1){
                dp[i] = 1;
            }
        }
    }
    for (int i = 1; i <= sum; ++i){
        if (dp[i]) order.push_back(i);
    }
    cout << order.size() << "\n";
    for (auto i : order){
        cout << i << " ";
    }
    return 0;
}