#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

ll n, f, t;
ll a[arr];

void checksum(){
    vector<ll> b;
    for (int i = 1; i <= n; ++i){
        b.push_back(a[i]);
    }
    sort (b.begin(), b.end(), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < f; ++i){
        sum += b[i];
    }
    if (sum < t){
        cout << "NO";
        exit(0);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("candy.inp","r")){
        freopen("candy.inp","r",stdin);
        freopen("candy.out","w",stdout);
    }
    cin >> n >> f >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    checksum();
    cout << 1;
    return 0;
}
