//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

//ll cakes[ARR], times[ARR];

pair<ll,ll> a[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    /*cakes[0] = times[0] = 0;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < i; ++j){
            if (abs(a[i].first - a[j].first) + a[i].second + times[j] <= t){
                if (cakes[i] < cakes[j] + 1){
                    cakes[i] = cakes[j] + 1;
                    times[i] = times[j] + abs(a[i].first - a[j].first) + a[i].second;
                }
                else if (cakes[i] == cakes[j] + 1){
                    times[i] = min(times[i], times[j] + abs(a[i].first - a[j].first) + a[i].second);
                }
            }
        }
        res = max(res , cakes[i]);
    }
    cout << res;*/
    ll res = 0, x = 0;
    priority_queue<ll> pq;
    for (int i = 1; i <= n; ++i){
        x += a[i].second;
        pq.push(a[i].second);
        if (x + a[i].first > t && !pq.empty()){
            x -= pq.top();
            pq.pop();
        }
        ll t = pq.size();
        res = max(res, t);
    }
    cout << res;
    return 0;
}