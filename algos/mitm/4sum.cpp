// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#define ll long long
#define task "4sum"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort (nums.begin(), nums.end());
    unordered_map<long long, vector<pair<int, int>>> sums;
    set<vector<int>> res_set;
    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            long long sum = nums[i] + nums[j];
            long long complement = target - sum;
            if (sums.count(complement)){
                for (auto p : sums[complement]){
                    res_set.insert({nums[p.first], nums[p.second], nums[i], nums[j]});
                }
            }
        }
        for (int k = 0; k < i; ++k){
            int sum_val = nums[k] + nums[i];
            sums[sum_val].push_back({k, i});
        }
    }
    vector<vector<int>> res(res_set.begin(), res_set.end());
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