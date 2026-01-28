#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s, cnt[arr];

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     cin >> s;
     for (ll i = 1; i <= s; i++){
          cin >> a[i];
          cnt[a[i]]++;
     } 
     ll t = INT_MAX;
     bool ok = 0;
     for (ll i = 1; i <= s; i++){
          if (cnt[a[i]] >= 2){
               ok = 1;
               for (ll j = i+1; j <= s; j++){
                    if (a[i] == a[j])
                    t = min(t,  abs(i - j));
               }
          }
     } 
     if (ok) cout << t << endl;
     else cout << -1 << endl;
     return 0;
}
