#include <iostream>
#include <cmath>
#define ll long long
#define task "cau1"

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    ll n1 = sqrt(n), k1 = sqrt(k);
    if (n1 * n1 < n) n1++;
    cout << k1 - n1 + 1;
    return 0;
}
