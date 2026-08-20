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


void sol(){
    fr(_,1,100){
        ofstream fcout("test.txt");
        int n,m,q;
        n = rnd(1,10);
        m = 2;
        q = rnd(1,10);
        fcout << n << " " << m << " " << q << "\n";
        fr(i,1,n){
            int x = rnd(0,1);
            fcout << x << " ";
        }
        fcout << "\n";
        while(q--){
            int type ;
            type = rnd(1,2);
            fcout << type << " ";
            if(type == 1){
                int l,r,c;
                l = rnd(1,n);
                r = rnd(l,n);
                c = rnd(1,100);
                fcout << l << " " << r << " " << c << "\n";
            }
            else if(type == 2){
                int l,r;
                l = rnd(1,n);
                r = rnd(l,n);
                fcout << l << " " << r << "\n";
            }
        }
        fcout.close();

        system("bai1good");
        system("VSEQ");
        if(system("fc ans.txt out.txt")){
            cout << "sai";
            return;
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
    init_world();
    sol();
    return 0;
}
/** /\_/\
 * (= ,_,)
 * / >TL \ >AC
*/
