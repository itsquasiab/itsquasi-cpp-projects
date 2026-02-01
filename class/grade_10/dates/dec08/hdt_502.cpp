#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ll case1 = n / 2;   //cases when a * a % (a + a) == 0 in which a is even
    ll t = case1;
    for (int i = 2; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ll mul = i * j, sum = i + j;
            if (mul % sum == 0){
                t++;
                //if (i != j && i & 1)
                //cout << i << " " << j << "\n";
            }
        }
    }
    cout << t;
}
