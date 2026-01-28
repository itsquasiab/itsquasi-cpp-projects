#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a,b,c,a1,b1,c1;
     cin >> a >> b >> c >> a1 >> b1 >> c1;

     cout << ((a + b - c == 0 || b + c - a == 0 || c + a - b == 0) ? "yes\n" : "no\n") << ((a1 + b1 - c1 == 0 || b1 + c1 - a1 == 0 || c1 + a1 - b1 == 0) ? "yes\n" : "no\n");
     return 0;
}
