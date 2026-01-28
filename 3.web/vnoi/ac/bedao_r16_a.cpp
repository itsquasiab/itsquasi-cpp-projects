#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     string a;

     getline(cin,a);

     //stringstream ss(a);
     if (a[0] == 'I' && a[1] == ' '){
     cout << "am" << endl;
     return 0;
     }
     else{
          if (a.find("We ") != string::npos) cout << "are\n";
          else if (a.find("They ") != string::npos) cout << "are\n";
          else if (a.find("You ") != string::npos) cout << "are\n";
          else cout << "is\n";
     }
     return 0;
}
