// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        stack<int> st;
        ll res = 0;
        for (int i = 1; i <= n; ++i){
            while (!st.empty() && a[st.top()] >= a[i]){
                ll past_height = a[st.top()];
                st.pop();
                int w = (st.empty() ? i - 1 : i - st.top() - 1);
                res = max(res, past_height * w);
            }
            st.push(i);
        }
        while (!st.empty()){
            ll past_height = a[st.top()];
            st.pop();
            int w = (st.empty() ? n : n - st.top());
            res = max(res, past_height * w);
        }
        cout << res << "\n";
    }
    return 0;
}