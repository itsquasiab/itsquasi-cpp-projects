#include <iostream>
#include <string>
#define ll long long
#define task "safe"

using namespace std;

const ll arr = 1e5 + 6, mod = 20240131;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    string a;
    cin >> n >> a;
    ll res = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 5; j < n; ++j){
            bool dg = 0, up = 0, lo = 0;
            for (int k = i; k <= j; ++k){
                if (isdigit(a[k])) dg = 1;
                else if (islower(a[k])) lo = 1;
                else if (isupper(a[k])) up = 1;
                if (dg && lo && up) break;
            }
            if (dg && lo && up) res++;
        }
    }
    cout << res;
    return 0;
}