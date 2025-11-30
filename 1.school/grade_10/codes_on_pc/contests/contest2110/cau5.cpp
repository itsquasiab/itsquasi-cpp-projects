#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000006];
ll f1[1000006], f2[1000006];

int s1 = 0, s2 = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen("cau1.inp","r")){
        freopen("cau1.inp","r",stdin);
        freopen("cau1.out","w",stdout);
    }*/
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(f1 + 1, f1 + s1 + 1, a[i]) - f1;
        f1[j] = a[i];
        s1 = max(s1, j);
    }
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(f2 + 1, f2 + s2 + 1, a[i]) - f2;
        f2[j] = a[i];
        s2 = max(s2, j);
    }
    cout << n - max(s1, s2);
    //cout << "\n" << n - min(s1, s2);
    return 0;
}
