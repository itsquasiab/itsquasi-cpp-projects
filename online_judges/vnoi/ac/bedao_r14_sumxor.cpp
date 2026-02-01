#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll findxor(ll x){
     if (x%4 == 0) return x;
     else if (x%4 == 1) return 1;
     else if (x%4 == 2) return x + 1;
     else return 0;
}

int main()
{
     ios_base::sync_with_stdio(NULL);
     cin.tie(0);
     cout.tie(0);

     ll s;
     cin >> s;
     while (s--)
     {
          ll l, r;
          cin >> l >> r;
          ll t = findxor(r) ^ findxor(l-1);
          /*for (ll i = l; i <= r; i++)
          {
               t = t ^ i;
          }*/
          cout << t << '\n';
     }
     return 0;
}
