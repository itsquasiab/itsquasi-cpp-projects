//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (n--){
        ll x;
        cin >> x;
        pq.push(x);
    }
    ll cst = 0;
    while (pq.size() > 1){
        int cnt = pq.size();
        if (cnt > k) cnt = k;

        ll sum = 0;
        ll mx = LLONG_MIN, mn = LLONG_MAX;

        for (int i = 0; i < cnt; ++i){
            sum += pq.top();
            mx = max(mx, pq.top());
            mn = min(mn, pq.top());
            pq.pop();
        }
        cst += mx - mn;
        pq.push(sum);
    }
    cout << pq.top() << "\n" << cst << '\n';
    return 0;
}