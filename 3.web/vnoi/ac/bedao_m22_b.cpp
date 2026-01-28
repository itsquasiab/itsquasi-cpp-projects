#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s;

map<ll,ll>cnt;

int main()
{
     ios_base::sync_with_stdio(NULL);
     cin.tie(0);
     cout.tie(0);

     cin >> s;
     ll res = 0;
     for (ll i = 1; i <= s; i++)
     {
          cin >> a[i];
          if (i >= 7){
               cnt[a[i-6]%23]++;
               res += cnt[a[i]%23];
          }
     }
     cout << res << endl;
     return 0;
}
