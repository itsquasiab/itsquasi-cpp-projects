//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arrm = 2224, arrn = 12, mod = 1e9 + 7;

int n, m;
vector<ii> node[arrm];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    ll a[m + 5][n + 5];
    ll b[m + 5];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
        cin >> b[i];
        if (i == 1){
            for (int j = 1; j <= n; ++j){
            node[0].push_back({});
            }
        }
    }
    return 0;
}