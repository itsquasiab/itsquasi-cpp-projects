/// created day : 2026-07-09
#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fx(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define FILE "VSEQ"
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

int n,m;
int q;
int a[N];
struct SEG{
    int len;
    vector<ll> tree,lazy;
    void init(int n ){
        len = n;
        tree.assign(n*4+2,0);
        lazy.assign(n*4+2,0);
    }
    void build(int idx,int l,int r){
        if(l == r){
            tree[idx] = a[l];
            return;
        }
        int mid = l+r >> 1;
        build(idx<<1 , l, mid);
        build(idx<<1|1,mid+1,r);
        tree[idx] = (tree[idx<<1] + tree[idx<<1|1]) % m;
    }
    void down(int idx,int l,int r,int mid){
        int x= lazy[idx] ;
        if(!x) return;
        tree[idx<<1] = (tree[idx<<1] + x) % m;
        tree[idx<<1|1] = (tree[idx<<1] + x) % m;

        lazy[idx<<1] += x;
        lazy[idx<<1|1] += x;
        lazy[idx]  = 0;
    }
    void update(int idx,int l,int r,int u,int v,int val){
        if(u > v || l > v || r < u) return;
        if(u <= l && r <= v){
            tree[idx] = (tree[idx] %m + val*(r-l+1) % m ) % m;
            lazy[idx] += val;
            return;
        }
        int mid = l+r >> 1;
        down(idx,l,r,mid);
        update(idx<<1,l,mid,u,v,val);
        update(idx<<1|1,mid+1,r,u,v,val);
        tree[idx] = (tree[idx<<1] + tree[idx<<1|1])%m;
    }
    int get(int idx,int l,int r,int u,int v){
        if(l > v || r < u || u > v)  return 0;
        if(u <= l && r <= v) return tree[idx]%m;
        int mid = l+r >> 1;
        down(idx,l,r,mid);
        return (get(idx<<1,l,mid,u,v) +
                get(idx<<1|1,mid+1,r,u,v)) % m;
    }
}seg;
namespace sub1{
    void sol(){
        while(q--){
        int type; cin >> type;
        if(type == 1){
            int l,r,c; cin >> l>> r >> c;
            fr(i,l,r){
                a[i] = (a[i] + c) % m ;
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
}
struct node{
    int x,l,r,c;
};
node test[N];
namespace sub2{
    int sum[N];
    void sol(){
        sum[0] = 0;
        fr(i,1,n) sum[i] = sum[i-1] + a[i];
        fr(i,1,q){
            auto [type,l,r,c] = test[i];
            int tong = sum[r] - sum[l-1];
            if(tong == (r-l+1) || tong == 0){
                cout << "0\n";
            }
            else cout <<"1\n";
        }
    }
}namespace sub3{
    struct SEG2{
        int len;
        vector<ll> tree;
        vector<int> lazy;
        void init(int n ){
            len = n;
            tree.assign(n*4+2,0);
            lazy.assign(n*4+2,0);
        }
        void build(int idx,int l,int r){
            if(l == r){
                tree[idx] = a[l];
                return;
            }
            int mid = l+r>>1;
            build(idx<<1,l,mid);
            build(idx<<1|1,mid+1,r);
            tree[idx] = tree[idx<<1] + tree[idx<<1|1];
        }
        void down(int idx,int l,int r,int mid){
            int x = lazy[idx];
            if(x == 0) return;
            lazy[idx<<1] += x;
            lazy[idx<<1] %= 2;
            lazy[idx<<1|1] %= 2;
            if(lazy[idx<<1] & 1  ) {
                tree[idx<<1] = (mid-l+1) - tree[idx<<1];
            }
            if(lazy[idx<<1|1] &1){
                tree[idx<<1|1] = (r-mid) - tree[idx<<1];
            }
            lazy[idx] = 0;
        }
        void update(int idx,int l,int r,int u,int v){
            if(u > r || l > v) return;
            if(u <= l && r <= v){
                tree[idx] = (r-l+1) - tree[idx];
                lazy[idx] = 1;
                return;
            }
            int mid = l+r>>1;
            down(idx,l,r,mid);
            update(idx<<1,l,mid,u,v);
            update(idx<<1|1,mid+1,r,u,v);
            tree[idx] = tree[idx<<1] + tree[idx<<1|1];
        }
        int get(int idx,int l,int r,int u,int v){
            if(u > r || l > v) return 0;
            if(u <= l && r <= v){
                if(lazy[idx]) tree[idx] = (r-l+1) - tree[idx];
                return tree[idx];
            }
            int mid = l+r>>1;
            down(idx,l,r,mid);
            return get(idx<<1,l,mid,u,v) + get(idx<<1|1,mid+1,r,u,v);
        }
    }seg2;
    void sol(){
        seg2.init(n);
        seg2.build(1,1,n);
        fr(i,1,q){
            auto [type,l,r,c] = test[i];
            if(type == 1){
                if(c&1){
                    // 1 thanh 0 con 0 - > 1
                    seg2.update(1,1,n,l,r);
                }
            }
            else {
                int tong = seg2.get(1,1,n,l,r);
                if(tong == (r-l+1) || tong == 0) {
                    cout << 0;
                }
                else cout << 1;
                cout << "\n";
            }
        }
    }
}
void sol(){
    cin >> n >> m >> q;
    fr(i,1,n){
        cin >> a[i];
    }

    if(n <= 1000 && q <= 1000){
        sub1::sol();
        return;
    }
    bool ok1 = true;
    fr(i,1,q){
        cin >> test[i].x;
        if(test[i].x == 1){
            int l,r,c; cin >> l >> r >> c;
            test[i].l = l;
            test[i].r = r;
            test[i].c = c;
            ok1 = false;
        }
        else{
            int l,r; cin >> l >> r;
            test[i].l = l;
            test[i].r = r;
        }
    }
    if(m == 2){
        sub3::sol();
        return;
    }
    if(ok1){
        sub2::sol();
        return;
    }
    seg.init(n);
    seg.build(1,1,n);
    fr(i,1,q){
        auto [type,l,r,c] = test[i];
        if(type == 1){
            seg.update(1,1,n,l,r,c);
        }
        else {
            ll tong = seg.get(1,1,n,l,r);
            ll dau = seg.get(1,1,n,l,l);
            if((dau*(r-l+1))  == tong ){
                cout << 0;
            }
            else cout << 1;
            cout << "\n";
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
//    freopen("test.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    init_world();
    sol();
    return 0;
}
/** /\_/\
 * (= ,_,)
 * / >TL \ >AC
*/
