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
        ll res = 0, pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n + 1; ++i){
            while (!st.empty() && a[st.top()] >= a[i]){
                int last = st.top();
                st.pop();
                int l = (st.empty() ? 1 : st.top() + 1);
                int r = (i - 1);
                int w = r - l + 1;
                if (res < a[last] * w){
                    res = a[last] * w;
                    pos1 = l;
                    pos2 = r;
                }
                else if (res == a[last] * w && l < pos1){
                    pos1 = l;
                    pos2 = r;
                }
            }
            st.push(i);
        }
        cout << res << " " << pos1 << " " << pos2 << "\n";
    }
    return 0;
}