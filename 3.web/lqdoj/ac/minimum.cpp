//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    deque<ll> dq;
    vector<ll> mn;
    for (int i = 1; i <= n; ++i){
        while (dq.size() && a[dq.back()] > a[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() + k <= i) dq.pop_front();
        if (i >= k) mn.push_back(a[dq.front()]);
    }
    for (auto i : mn){
        cout << i << "\n";
    }
    return 0;
}