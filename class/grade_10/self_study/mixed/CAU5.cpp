#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int limit = 1e6 + 6;

ll a[limit];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    int res = INT_MAX;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll sum = 0;
    bool ok = 0;
    for (int i = 1, j = 1; j <= n; ++j){
        sum += a[j];
        while (sum > k){
            res = min(res, j - i + 1);
            sum -= a[i];
            i++;
            ok = 1;
        }
    }
    cout << (ok ? res : -1);
    return 0;
}


