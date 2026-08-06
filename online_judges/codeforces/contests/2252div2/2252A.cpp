// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define ll long long
#define task "2252A"

using namespace std;

struct Node {
    int cnt;
    ll val;
    bool operator<(const Node &other) const {
        if (cnt != other.cnt) return cnt < other.cnt; // larger count first
        return val < other.val;                       // then larger value
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        map<ll, int> mp;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            mp[x]++;
        }

        priority_queue<Node> pq;
        for (auto [v, c] : mp)
            pq.push({c, v});

        vector<ll> ord;
        ll last = LLONG_MIN;

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            if (cur.val != last) {
                ord.push_back(cur.val);
                last = cur.val;
                cur.cnt--;
                if (cur.cnt) pq.push(cur);
            } else {
                if (pq.empty()) {
                    ord.push_back(cur.val);
                    cur.cnt--;
                    if (cur.cnt) pq.push(cur);
                    last = cur.val;
                } else {
                    Node nxt = pq.top();
                    pq.pop();

                    ord.push_back(nxt.val);
                    last = nxt.val;
                    nxt.cnt--;
                    if (nxt.cnt) pq.push(nxt);

                    pq.push(cur);
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < (int)ord.size(); i++) {
            ans += ord[i];
            if (i && ord[i] == ord[i - 1])
                break;
        }

        cout << ans << '\n';
    }

    return 0;
}