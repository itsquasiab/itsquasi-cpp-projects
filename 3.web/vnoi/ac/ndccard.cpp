//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    ll mx = 0;
    bool f = 0;
    for (int i = 1; i <= n - 2; ++i){
        if (f) break;
        ll tar = m - a[i];
        int l = i + 1, r = n;
        while (l < r){
            if (a[l] + a[r] == tar){
                mx = m;
                f = 1;
                break;
            }
            else if (a[l] + a[r] < tar){
                mx = max(mx, a[l] + a[r] + a[i]);
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << mx;
    return 0;
}