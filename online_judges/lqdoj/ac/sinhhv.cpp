//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

int n;
vector<int> s;
unordered_map<int, bool> used;

void backtrack(int p){
    if (p > n){
        for (int i : s) cout << i;
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i){
        if (!used[i]){
            used[i] = 1;
            s.push_back(i);
            backtrack(p + 1);
            s.pop_back();
            used[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    backtrack(1);
    return 0;
}