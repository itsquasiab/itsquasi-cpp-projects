#include <iostream>
#define ll long long
#define task "cau1"

using namespace std;

int rem(ll a, ll b){
    ll n = a * b;
    int cnt = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            cnt *= (e + 1);
        }
    }
    if (n > 1) cnt *= 2;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n;
    cin >> n;
    while (n--){
        ll a, b;
        cin >> a >> b;
        cout << rem(a, b) << "\n";
    }
    return 0;
}