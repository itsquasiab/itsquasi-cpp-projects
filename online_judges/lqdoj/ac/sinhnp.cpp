//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

int n;
string s = "";

void backtrack(int pos){
    if (pos > n){
        cout << s << "\n";
        return;
    }
    for (char i = '0'; i <= '1'; ++i){
        s.push_back(i);
        backtrack(pos + 1);
        s.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    backtrack(1);
    return 0;
}