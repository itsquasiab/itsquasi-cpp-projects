// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    stack<ll> st;
    a[n + 1] = 0;
    ll res = 0;
    for (int i = 1; i <= n + 1; ++i){
        ll h = 0, w = 0;
        while (!st.empty() && a[st.top()] > a[i]){
            h = a[st.top()], st.pop();
            if (st.empty()) w = i - 1;
            else w = i - st.top() - 1;
            res = max(res, h * w);
        }
        st.push(i);
    }
    cout << res;
    return 0;
}