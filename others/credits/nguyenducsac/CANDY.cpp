/// created day : 2026-07-09
#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fx(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define FILE "CANDY"
using namespace std;
using ll = long long;
const int N = 1e6+7;
const int mod = 1e9+7;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
const ll inf = 1e18+3;
const int INF = 1e9+7;

mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){
    return uniform_int_distribution<int>(l,r)(Rand);
}
const int base = 311+rnd(1,1000);

int m,t;
int d[N];
void sol(){
    cin >> m >> t;
    fr(i,1,m){
        cin >> d[i];
    }
    sort(d + 1 , d+m+1);
    while(t -- ){
        int n; cin >> n;
        if(n % m == 0){
            cout << "0 ";
            continue;
        }
        n = n%m;
        ll tong = 0;
        fr(i,1,m-n){
            tong += d[i] * n;
        }
        cout << tong << " ";
    }
}
void init_world(){

}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    if(fopen(FILE".inp","r")){
        freopen(FILE".inp","r",stdin);
        freopen(FILE".out","w",stdout);
    }
    init_world();
    sol();
    return 0;
}
/** /\_/\
 * (= ,_,)
 * / >TL \ >AC
*/
