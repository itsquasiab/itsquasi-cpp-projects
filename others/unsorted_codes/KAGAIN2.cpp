// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long
#define task "KAGAIN"

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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        a[n + 1] = 0;
        stack<int> st;
        ll res = 0;
        int lpos = 1, rpos = 1;
        for (int i = 1; i <= n + 1; ++i){
            while (!st.empty() && a[st.top()] >= a[i]){
                int last = st.top();
                st.pop();

                int l = st.empty() ? i : st.top() - 1;
                int r = i;
                ll w = r - l;
                //cout << l << " " << r << " | ";
                //cout << a[last] << " " << w << "\n";
                if (res < a[last] * w){
                    res = a[last] * w;
                    lpos = l;
                    rpos = r;
                }
                else if (res == a[last] * w && l < lpos){
                    lpos = l;
                    rpos = r;
                }
            }
            st.push(i);
        }
        while (!st.empty()) {
            int last = st.top(); st.pop();
            ll curr = a[last] * (st.empty() ? n : n - st.top() - 1);
            int l = st.empty() ? n : st.top() - 1;
            int r = n;
            ll w = r - l;
            if (res < a[last] * w){
                res = a[last] * w;
                lpos = l;
                rpos = r;
            }
            else if (res == a[last] * w && l < lpos){
                lpos = l;
                rpos = r;
            }
        }
        cout << res << " " << lpos << " " << rpos << "\n";
    }
    return 0;
}