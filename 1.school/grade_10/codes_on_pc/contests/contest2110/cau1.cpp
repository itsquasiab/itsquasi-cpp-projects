#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen("cau1.inp","r")){
        freopen("cau1.inp","r",stdin);
        freopen("cau1.out","w",stdout);
    }*/
    ll n;
    cin >> n;
    if (n & 1) cout << (n + 1) / 2 * -1;
    else cout << n / 2;
    return 0;
}
