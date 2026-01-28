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
    freopen("closest.inp", "r", stdin);
    freopen("closest.out", "w", stdout);
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        while (!st.empty() && a[st.top()] >= a[i]){
            //cout << st.top() << " - ";
            st.pop();
        }
        if (st.empty()) cout << 0 << " ";
        else cout << st.top() << " ";
        st.push(i);
    }
    return 0;
}