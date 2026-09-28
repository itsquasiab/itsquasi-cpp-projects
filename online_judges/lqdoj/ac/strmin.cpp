// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <stack>
#define ll long long
#define task "strmin"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int k;
    string s;
    cin >> k >> s;
    stack<char> st;
    ll del = s.size() - k;
    for (char c : s){
        while (!st.empty() && st.top() > c && del > 0){
            st.pop();
            del--;
        }
        st.push(c);
    }
    while (del > 0 && !st.empty()) st.pop(), del--;
    string res = "";
    while (!st.empty() && k){
        res = st.top() + res;
        st.pop();
        k--;
    }
    cout << res;
    return 0;
}