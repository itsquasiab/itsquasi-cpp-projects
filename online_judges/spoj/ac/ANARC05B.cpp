// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define task "ANARC05B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

struct intersection
{
    ll val;
    int pos_1;
    int pos_2;
};


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    while (1){
        unordered_map<ll, int> exist;
        vector<intersection> inter;
        unordered_map<ll, bool> is_intersection;
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) cin >> a[i], exist[a[i]] = i;
        int m;
        cin >> m;
        if (m == 0) break;
        for (int i = 1; i <= m; ++i){
            cin >> b[i];
            if (exist.count(b[i])){
                inter.push_back({b[i], exist[b[i]], i});
                is_intersection[b[i]] = 1;
            }
        }
        vector<ll> pf1, pf2;
        ll sum = 0;
        for (int i = 1; i <= n; ++i){
            if (is_intersection[a[i]]) pf1.push_back(sum), sum = 0;
            sum += a[i];
        }
        pf1.push_back(sum), sum = 0;
        for (int i = 1; i <= m; ++i){
            if (is_intersection[b[i]]) pf2.push_back(sum), sum = 0;
            sum += b[i];
        }
        pf2.push_back(sum);

        vector<ll> dp(max(m, n + 5), 0);
        for (int i = 1; i <= pf1.size(); ++i){
            dp[i] = max(dp[i - 1] + pf1[i - 1], dp[i - 1] + pf2[i - 1]);
        }
        cout << dp[pf1.size()] << "\n";
    }
    return 0;
}