// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "ds11"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

deque<ll> mn, mx;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll s, d;
    cin >> n >> s >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1, j = 1, res = 0;
    ll sum = 0;
    while (i <= n && j <= n){
        sum += a[j];
        while (mx.size() && a[mx.back()] <= a[j]) mx.pop_back();
        while (mn.size() && a[mn.back()] >= a[j]) mn.pop_back();
        mx.push_back(j);
        mn.push_back(j);
        while (mx.size() && mn.size() && a[mx.front()] - a[mn.front()] > d){
            sum -= a[i];
            if (mx.size() && mx.front() == i) mx.pop_front();
            if (mn.size() && mn.front() == i) mn.pop_front();
            i++;
        }
        //cout << i << " " << j << " ";
        while (sum >= s){
            cout << "valid\n";
            res++;
            sum -= a[i];
            if (mx.size() && mx.front() == i) mx.pop_front();
            if (mn.size() && mn.front() == i) mn.pop_front();
            i++;
            //cout << i << " " << j << " ";
        }
        j++;
        //cout << "\n";
    }
    cout << res;
    return 0;
}