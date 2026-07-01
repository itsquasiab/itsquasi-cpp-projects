//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll mx = 0;
    string res;
    for (int i = 0; i < n; ++i){
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]){
            if (r - l + 1 > mx){
                mx = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            else if (r - l + 1 == mx){
                string temp = s.substr(l, r - l + 1);
                res = max(res, temp);
            }
            l--, r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]){
            if (r - l + 1 > mx){
                mx = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            else if (r - l + 1 == mx){
                string temp = s.substr(l, r - l + 1);
                res = max(res, temp);
            }
            l--, r++;
        }
        //cout << res << " ";
    }
    cout << mx << "\n" << res;
    return 0;
}
