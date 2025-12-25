//Minding my own business. :)
//MADE BY ITSQUparI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], par[arr];
int dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int len = 0, pos = 0;
    for (int i = 1; i <= n; ++i){
        dp[i] = 1;
        for (int j = 1; j < i; ++j){
            if (a[j] < a[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        if (dp[i] > len){
            len = dp[i];
            pos = i;
        }
    }
    int cur = pos;
    vector<ll> seq;
    while (cur != 0){
        seq.push_back(a[cur]);
        cur = par[cur];
    }
    cout << len << "\n";
    for (int i = seq.size() - 1; i >= 0; --i){
        cout << seq[i] << " ";
    }
    return 0;
}