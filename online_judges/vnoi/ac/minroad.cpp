//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

pair<ll, ll> a[ARR];
ll c1[ARR], c2[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        c1[i] = c1[i - 1] + (a[i].second == 1);
        c2[i] = c2[i - 1] + (a[i].second == 2);
        //cout << a[i].first << " " << a[i].second << "\n";
    }
    if (c1[n] < x || c2[n] < y){
        cout << -1;
        return 0;
    }
    ll mx = LLONG_MAX;
    for (int i = 1, j = 1; j <= n; ++j){
        ll x1 = c1[j] - c1[i - 1];
        ll y1 = c2[j] - c2[i - 1];
        while (x1 >= x && y1 >= y){
            mx = min(mx, a[j].first - a[i].first);
            i++;
            x1 = c1[j] - c1[i - 1];
            y1 = c2[j] - c2[i - 1];
        }
    }
    cout << mx;
    return 0;
}