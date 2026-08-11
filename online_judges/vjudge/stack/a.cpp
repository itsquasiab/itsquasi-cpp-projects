// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long
#define task "a"

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    stack<ll> st;
    cout << 0 << " ";
    st.push(1);
    for (int i = 2; i <= n; ++i){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) cout << 0 << " ";
        else cout << st.top() << " ";
        st.push(i);
    }
    return 0;
}