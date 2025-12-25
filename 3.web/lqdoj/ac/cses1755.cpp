#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string a;
unordered_map<char, int> cnt;
char midchar;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a;
    for (int i = 0; i < a.size(); ++i){
        cnt[a[i]]++;
    }
    int odd = 0;
    for (auto i : cnt){
        if (i.second & 1) odd++, midchar = i.first;
    }
    if (odd > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    char saved;
    int num = 0;
    string left, right, mid;
    for (auto i : cnt){
        char c = i.first;
        int k = i.second;
        if (k & 1) continue;
        left.append(k / 2, c);
        right.append(k / 2, c);
    }
    if (odd == 1) {
        mid.append(cnt[midchar], midchar);
    }

    reverse(right.begin(), right.end());

    cout << left + mid + right;
    return 0;
}