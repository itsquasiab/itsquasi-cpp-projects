#include <iostream>
#include <string>
#define ll long long
#define task "cau2"

using namespace std;

bool is_vowel(char c){
    if (c == 'U' || c == 'E' || c == 'O' || c == 'A' || c == 'I') return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1){
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == 'H')
            for (int j = i + 1; j < s.size(); ++j){
                if (s[j] == 'S')
                for (int k = j + 1; k < s.size(); ++k){
                    if (s[k] == 'G') cnt++;
                }
            }
        }
        cout << cnt;
    }
    else{
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == 'H')
            for (int j = i + 1; j < s.size(); ++j){
                if (is_vowel(s[j])) break;
                if (s[j] == 'S')
                for (int k = j + 1; k < s.size(); ++k){
                    if(is_vowel(s[k])) break;
                    if (s[k] == 'G') cnt++;
                }
            }
        }
        cout << cnt;
    }
    return 0;
}