#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
struct kbc{
    ll a, b, num;
};
kbc a[arr];
ll dp[arr];

bool sorter(kbc a, kbc b){
    return a.a < b.a || (a.a == b.a && a.b < b.b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].a >> a[i].b;
        a[i].num = a[i].b - a[i].a;
    }
    sort (a + 1, a + 1 + n, sorter);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i){
        dp[i] = a[i].num;
        for (int j = 1; j < i; ++j){
            if (a[j].b <= a[i].a)
            dp[i] = max(dp[i], dp[j] + a[i].num);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}