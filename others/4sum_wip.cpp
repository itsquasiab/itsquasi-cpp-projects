// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long
#define task "4sum"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort (nums.begin(), nums.end());
    unordered_map<long long, vector<pair<int, int>>> sums;
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i){
        if (i > 0 && nums[i] == nums[i - 1]){
            for (int k = 0; k < i; ++k){
                if (k > 0 && nums[k] == nums[k - 1]) continue;
                long long pair_sum = nums[k] + nums[i];
                if (!sums.count(pair_sum)){
                    sums[pair_sum].push_back({k, i});
                }
                else {
                    int lk = sums[pair_sum].back().first;
                    int li = sums[pair_sum].back().second;
                    if (nums[lk] != nums[k] || nums[li] != nums[i]) sums[pair_sum].push_back({k, i});
                }
            }
        }
        for (int j = i + 1; j < n; ++j){
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long sum_val = nums[i] + nums[j];
            long long complement = target - sum_val;
            if (sums.count(complement)){
                for (auto p : sums[complement]){
                    res.push_back({nums[p.first], nums[p.second], nums[i], nums[j]});
                }
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    
    return 0;
}