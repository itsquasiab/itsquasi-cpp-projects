// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, a;

void multiply(vector<int>& result, int n) {
    int carry = 0;
    for (int i = 0; i < result.size(); i++) {
        int prod = result[i] * n + carry;
        result[i] = prod % 10; // Store the last digit
        carry = prod / 10;     // Keep the carry
    }
    // Add remaining carry digits to the end of the vector
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n) {
    // Initialize result with 1 (1! = 1), storing digits in reverse order
    vector<int> result(1, 1); 

    // Multiply the result by numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        multiply(result, i);
    }

    // Print the result digits in reverse order (from end to beginning)
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    while (n--){
        cin >> a;
        factorial(a);
    }
    return 0;
}