//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pf[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    deque<ll> dq;
    ll res = LLONG_MIN;
    for (int i = 1; i <= n; ++i){
        if (i - l >= 0){
            while (!dq.empty() && pf[dq.back()] > pf[i - l]){
                dq.pop_back();
            }
            dq.push_back(i - l);
        }

        while (!dq.empty() && dq.front() < i - r) dq.pop_front();
        if (!dq.empty()) res = max(res, pf[i] - pf[dq.front()]);
    }
    cout << res;
    return 0;
}