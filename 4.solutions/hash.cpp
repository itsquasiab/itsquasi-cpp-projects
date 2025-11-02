//Welcome to your new home, CLCer ItsQuasi!
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string t, p;
const ll base = 31;
const ll mod = 1000000003;

ll hash_str[1000006], prefix_base[1000006];

void create_prefix_base(int len_t){
    for (int i = 1; i <= len_t; ++i){
        prefix_base[i] = (prefix_base[i - 1] * base) % mod;
    }
}

void create_hash(int len_t){
    for (int i = 1; i <= len_t; ++i){
        hash_str[i] = (hash_str[i - 1] * base + t[i] - 'a' + 1) % mod;
    }
}

ll get_hash(int i, int j){
    return (hash_str[j] - hash_str[i - 1] * prefix_base[j - i + 1] + mod * mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t >> p;
    int len_t = t.size(), len_p = p.size();
    t = " " + t;
    p = " " + p;
    prefix_base[0] = 1;

    create_prefix_base(len_t);

    create_hash(len_t);

    ll hashp = 0;
    for (int i = 1; i <= len_p; ++i){
        hashp = (hashp * base + p[i] - 'a' + 1) % mod;
    }
    ll t = 0;
    for (int i = 1; i <= len_t - len_p + 1; i++)
        if (hashp == get_hash(i, i + len_p - 1)) cout << i << " ";
    return 0;
}