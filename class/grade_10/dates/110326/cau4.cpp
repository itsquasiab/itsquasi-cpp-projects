#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
#define task "cau4"

using namespace std;

const ll arr = 1e6 + 6;

int n;
ll a[arr];
ll l[arr];
ll r[arr];

ll fmx(){
    stack<ll> s;
    for (int i = 1; i <= n; ++i){
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        if (s.empty()) l[i] = 1;
        else l[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (s.empty()) r[i] = n;
        else r[i] = s.top() - 1;
        s.push(i);
    }
    ll t = 0;
    for (int i = 1; i <= n; ++i){
        ll sd = (i - l[i] + 1) * (r[i] - i + 1);
        t = t + a[i] * sd;
    }
    return t;
}

ll fmn(){
    stack<ll> s;
    for (int i = 1; i <= n; ++i){
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        if (s.empty()) l[i] = 1;
        else l[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) r[i] = n;
        else r[i] = s.top() - 1;
        s.push(i);
    }
    ll t = 0;
    for (int i = 1; i <= n; ++i){
        ll sd = (i - l[i] + 1) * (r[i] - i + 1);
        t = t + a[i] * sd;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cout << fmx() - fmn();
    return 0;
}