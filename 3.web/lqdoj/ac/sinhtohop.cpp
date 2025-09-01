//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

int n, m, cnt = 0;
vector<ll> s;
unordered_map<ll, bool> used;

bool checkcp(ll x){
    ll t = sqrt(x);
    return t * t == x;
}

void backtrack(int p, int start){
    if (p > n){
        ll mul = 1;
        for(ll i : s){
            cout << i << " ";
            mul *= i;
        }
        if (checkcp(mul)) cnt++;
        cout << "\n";
        return;
    }
    for (int i = start; i <= m; ++i){
        if (!used[i]){
            s.push_back(i);
            backtrack(p + 1, i + 1);
            s.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    backtrack(1, 1);
    cout << cnt;
    return 0;
}