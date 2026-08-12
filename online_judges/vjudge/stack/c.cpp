// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define task "c"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

bool t[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            if (c == '.') t[i][j] = 1;
            else t[i][j] = 0;
        }
    }
    vector<ll> a(m + 2, 0);
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (t[i][j] == 1) a[j] = a[j] + 1;
            else a[j] = 0;
        }
        stack<ll> st;
        for (int i = 1; i <= m + 1; ++i){
            ll h = 0, w = 0;
            while (!st.empty() && a[st.top()] > a[i]){
                h = a[st.top()], st.pop();
                if (st.empty()) w = i - 1;
                else w = i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }
    }
    cout << res;
    return 0;
}