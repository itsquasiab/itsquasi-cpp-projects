#include<bits/stdc++.h>

using namespace std;

//answer correct
int n;
int main(){
    cin >> n;
    int d = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n%i==0){
            if (i!=sqrt(n)) d+=2;
            else if (i==sqrt(n)) d++;
        }
    }
    cout << d;
    return 0;
}
