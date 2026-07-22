// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "hn_hsg9_22_c"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll mb_per_sec, mb_download_per_sec, vid_len;

bool check(ll wait_time, ll max_time){
    ll downloaded = wait_time * mb_download_per_sec;
    ll start_watching = 0;
    for (int i = wait_time + 1; i <= max_time; ++i){
        downloaded += mb_download_per_sec;
        start_watching += mb_per_sec;
        if (start_watching > downloaded) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> mb_per_sec >> mb_download_per_sec >> vid_len;
    ll vid_len_mb = mb_per_sec * vid_len;
    ll max_time = vid_len_mb / mb_download_per_sec;
    ll l = 0, r = max_time, res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (check(mid, max_time)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}