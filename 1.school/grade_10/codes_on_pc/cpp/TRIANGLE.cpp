#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int limit = 1006;

ll a[limit][limit];

/*ll getsum(ll x, ll y, ll k){
    ll x1 = x + k - 1;
    ll y1 = y + k - 1;
    return pf[x1][y1] - pf[x - 1][y] - pf[x][y - 1] + pf[x - 1][y - 1];
}*/

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    ll mx = 0, sum = 0;
    for (int i = 1; i <= n - k + 1; ++i){
        for (int j = 1; j <= m - k + 1; ++j){

            for (int x = 1; x <= k; ++x){
                for (int y = 1; y <= x; ++y){
                    sum += a[i + x - 1][j + y - 1];
                    //cout << i + x - 1 << " " << j + y - 1 << " | ";
                    //cout << a[i + x - 1][j + y - 1] << " | ";
                }
                //cout << sum;
                //cout << "\n";
            }
            mx = max(mx, sum);
            sum = 0;
            //cout << "\n";
        }
    }
    //cout << "\n";
    cout << mx;
    return 0;
}


