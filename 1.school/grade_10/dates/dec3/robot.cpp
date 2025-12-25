#include<iostream>
#define ll long long
#define tname "robot"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
string a[arr];
int mxdigit[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k;
    int mxd = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int t = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            bool f = 0;
            if (i == j) continue;
            for (int k1 = 0; k1 < k; ++k1){
                if (a[i][k1] > a[j][k1]){
                    f = 1;
                    break;
                }
            }
            if (f == 0){
                t++;
                break;
            }
        }
    }
    cout << t;
    return 0;
}
