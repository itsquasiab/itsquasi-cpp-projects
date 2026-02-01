#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s, dp[arr], k;

int main()
{
     ios_base::sync_with_stdio(NULL);
     cin.tie(0);
     cout.tie(0);

     cin >> s >> k;
     for (ll i = 1; i <= s; i++)
     {
          cin >> a[i];
     }
     ll cnt = 0;
     dp[1] = 0;
     for(int i = 2; i <= s; ++i){
          ll minj = INT_MAX;
          for(int j = 1 ; j <= k; j++){
               if (i - j >= 1)
               minj = min(minj, dp[i - j] + abs(a[i] - a[i - j]));
          dp[i] = minj;
          }
     }
     cout << dp[s]; 
     return 0;
}
