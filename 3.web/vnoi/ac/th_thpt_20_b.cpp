#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s;

int cnt[arr];

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     if (fopen ("Cau2.inp","r")){
     freopen("Cau2.inp","r",stdin);
     freopen("Cau2.out","w",stdout);}

     cin >> s;
     for (ll i = 1; i <= s; i++){
          cin >> a[i];
          cnt[a[i]]++;
     } 
     ll t = cnt[a[1]];
     for (ll i = 2; i <= s; i++){
          if (cnt[a[i]] > t) t = cnt[a[i]];
     } 
     cout << t;
     return 0;
}
