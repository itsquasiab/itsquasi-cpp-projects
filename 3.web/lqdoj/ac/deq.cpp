//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<ll> b;
    b.push_back(0);
    stack<ll> st;
    st.push(1);
    for (int i = 2; i <= n; ++i){
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) b.push_back(0);
        else b.push_back(a[st.top()]);
        st.push(i);
    }
    for (auto i : b){
        cout << i << " ";
    }
    return 0;
}