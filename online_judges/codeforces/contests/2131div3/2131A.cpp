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
        ll a[n + 5], b[n + 5];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        ll tm = 1;
        bool eq = 1;
        while (eq){
            bool step1 = 0, step2 = 0;
            for (int i = 1; i <= n; ++i){
                if (a[i] > b[i]){
                    a[i]--;
                    step1 = 1;
                }
                if (a[i] < b[i]){
                    a[i]++;
                    step2 = 1;
                }
                if ((step1 == 1 && step2 == 1) || (step1 == 1 && step2 == 0)){
                    tm++;
                    break;
                }
            }
            //cout << step1 << " " << step2 << "\n";
            if (step1 == 0){
                eq = 0;
                break;
            }
        }
        cout << tm << "\n";
    }
    return 0;
}