/// created day : 2026-07-09
#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fx(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define FILE "name"
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


int n,m,q;
int a[N];
void sol(){
     cin >> n >> m >>q;
     fr(i,1,n){
        cin >> a[i];
     }
     while(q--){
        int type; cin >> type;
        if(type == 1){
            int l,r,c; cin >> l>> r >> c;
            fr(i,l,r){
                a[i] = (a[i] + c) % m;
            }
        }
        else{
            int l,r; cin >> l >> r;
            int mi = -1, mx = -1;
            fr(i,l,r){
                if(mi == -1 || a[i] < mi) mi = a[i];
                if(mx == -1 || a[i] > mx) mx = a[i];
            }
            if(mi != mx){
                cout << "1\n";
            }
            else cout << "0\n";
        }
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
    freopen("test.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    init_world();
    sol();
    return 0;
}
/** /\_/\
 * (= ,_,)
 * / >TL \ >AC
*/
