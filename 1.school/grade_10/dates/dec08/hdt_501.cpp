#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, d, z, x;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d;
    while (d){

        if (n > z + 1){
            z++;
            n -= z;
            d--;
        }
        else {
            n++;
            z = 0;
        }
        //cout << n << " ";
        x++;
    }
    cout << x;
}
