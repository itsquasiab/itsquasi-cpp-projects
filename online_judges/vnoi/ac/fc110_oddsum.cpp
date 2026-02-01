#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     cin >> s;
     for (ll i = 0; i < s; i++){
          cin >> a[i];
     } 
     ll t = 0;
     for (ll i = 1; i < s; i+=2){
          t += a[i];
     } 
     cout << t << endl;
     return 0;
}
