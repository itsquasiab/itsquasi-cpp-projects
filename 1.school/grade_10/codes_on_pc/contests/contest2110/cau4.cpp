#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000006];

ll sumsf, summx;
int l = 1, r = 1, tmpl = 1, tmpr = 1;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen("cau1.inp","r")){
        freopen("cau1.inp","r",stdin);
        freopen("cau1.out","w",stdout);
    }*/
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sumsf = a[1], summx = a[1];
    for (int i = 2; i <= n; ++i){
        if (sumsf + a[i] > a[i]){
            sumsf += a[i];
        }
        else {
            sumsf = a[i];
            tmpl = i;
        }
        tmpr++;
        if (sumsf > summx){
            summx = sumsf;
            r = tmpr;
            l = tmpl;
        }
        //cout << l << " " << r << "\n";
    }
    cout << summx << "\n";
    for (int i = l; i <= r; ++i){
        cout << a[i] << " ";
    }
    return 0;
}
