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
     for (ll i = 1; i <= s; i++){
          cin >> a[i];
          cout << (a[i]+1) / 2 + (a[i] % 2 == 0 ? 1 : 0) << endl;
     } 
     return 0;
}
