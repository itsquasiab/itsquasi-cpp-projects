#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a;
     cin >> a;
     while(a--){
          ll l,r;
          cin >> l >> r;
          if (l <= 2 && r <= 1 || l <= 1 && r <= 2)
          cout << "Yes" << endl;
          else
          cout << "No" << endl;
     }
     return 0;
}
