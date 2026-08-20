/// created day : 2026-07-09
#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fx(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define FILE "DIAGAME"
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

ll dp[105][105];
ll dpt[105][105];
int a[105][105];
int n,m;
bool check(int val1,int val2){
    if(val1 == 2 && val2 == 1 ) return false;
    if(val1 == 1 && val2 == 2 ) return false;

    return true;
}
int val(int x){
    if(x != 0) return 1;
    else return 0;
}
int so(int mask , int x){
    return (mask >> (x-1)) & 1;
}
namespace sub5{
    int dp[105][1505];
    void sol(){
        for(int mask1 = 1; mask1 <= (1<<n);++mask1){
            bool ok = true;
            int tong = 0;
            fr(i,1,m){
                if(i > 1 && so(mask1,i) && so(mask1,i-1)&& !check(a[1][i],a[1][i-1])) ok = false;
                if(!ok) break;
                if(so(mask1,i)) {
                    tong += val(a[1][i]);
                    if(a[1][i] == 3) ++ tong;
                    //if(a[1][i] == 3 && (i == 1 || a[1][i-1] == 0 || so(mask1,i-1) == 0) && (i== m || a[1][i+1] == 0 || so(mask1,i+1) == 0) ) tong++;
                }
            }
            if(ok) dp[1][mask1] = tong;
        }
        fr(i,2,n){
            for(int mask1 = 1; mask1 <= (1<<n);++mask1){
                if(dp[mask1] == 0) continue;
                for(int mask2 = 1; mask2 <= (1<<n);++mask2){
                    bool ok = true;
                    int tong = 0;
                    fr(j,1,m){
                        if(so(mask2,j) == 0) continue;
                        if(j > 1 && so(mask2,j) && so(mask2,j-1)&& !check(a[i][j],a[i][j-1])) ok = false;
                        if(so(mask1,j) && so(mask2,j) && !check(a[i-1][j],a[i][j]))  ok = false;
                        if(!ok) break;
                        tong += val(a[i][j]);
                        if(a[i][j] == 3) ++ tong;
                        //if(a[i][j] == 3 && (j == 1 || a[i][j-1] == 0 || so(mask2,j-1) == 0) && (j== m || a[i][j+1] == 0 || so(mask2,j+1) == 0) && (so(mask1,j) == 0 ||so(mask1,j) && a[i-1][j] == 0)) tong++;
                    }
                    if(ok){
                        dp[i][mask2] = max(dp[i][mask2],dp[i-1][mask1] + tong );
                    }
                }
            }
        }
        int ans = 0 ;
        for(int mask1 = 1; mask1 <= (1<<n);++mask1){
            ans = max(ans, dp[n][mask1]);
        }
        cout << ans;
    }
}
namespace sub2{
    int dp[100][2];
    void sol(){
        fr(i,1,m){
            if(i == 1){
                dp[i][1] = val(a[1][i]);
            }
            else{
                if(check(a[1][i], a[1][i-1]))
                    dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + val(a[1][i]);
                else dp[i][1] = dp[i-1][0] + val(a[1][i]);
                dp[i][0] = max(dp[i-1][0] ,dp[i-1][1]);
            }
        }
        cout << max(dp[m][0],dp[m][1]);
    }
}
namespace sub3{
    void sol(){
        int t1= 0 ,t2= 0;
        fr(i,1,n){
            fr(j,1,m){
                if((i+j) % 2 == 0) t2 += 2;
                else t1 += 2;
            }
        }
        cout << max(t1,t2);
    }
}
int na[105][105];
void sol(){
    cin >> n >> m;
    bool ok3 = true;
    fr(i,1,n){
        fr(j,1,m){
            cin >> a[i][j];
            if(a[i][j] != 3) ok3 = false;
        }
    }
//    if(n == 1){
//        sub2::sol();
//        return;
//    }
//    if(ok3){
//        sub3::sol();
//        return;
//    }
    if(n <= 5 || m <= 5){
        if(m <= 5){
            sub5::sol();
            return;
        }
        if(n <= 5){
            fr(i,1,m){
                fr(j,1,n){
                    na[i][j] = a[j][i];
                }
            }
            swap(n,m);
            fr(i,1,n){
                fr(j,1,m) a[i][j] = na[i][j];
            }
        }
        sub5::sol();
        return;
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
