//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
int nxt[arr];
int up[20][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    stack<int> st;
    for (int i = n; i >= 1; --i){
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        nxt[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; ++i)
        up[0][i] = nxt[i];

    for (int k = 1; k < 20; ++k){
        for (int i = 1; i <= n; ++i){
            up[k][i] = up[k-1][ up[k-1][i] ];
        }
    }

    while (q--){
        int l, r;
        cin >> l >> r;

        int cur = l;
        int ans = 1;

        for (int k = 20 - 1; k >= 0; --k){
            if (up[k][cur] && up[k][cur] <= r){
                ans += (1 << k);
                cur = up[k][cur];
            }
        }

        cout << ans << '\n';
    }
    return 0;
}