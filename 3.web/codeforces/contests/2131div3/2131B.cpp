//By truequasi2010, contest: Codeforces Round 1042 (Div. 3), problem: (B) Alternating Series, Wrong answer on test 2, #, Copy
//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll arr = 1e6 + 6, mod = 1e9;
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        if (n & 1){
            for (int i = 1; i <= n - 2; i += 2){
                cout << -1 << " " << 3 << " ";
            }
            cout << -1;
        }
        else {
            for (int i = 1; i <= n - 2; i += 2){
                cout << -1 << " " << 3 << " ";
            }
            cout << "-1 2";
        }
        cout << "\n";
    }
    return 0;
}