class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& ans,
               int start,
               vector<vector<int>>& subsets) {

        subsets.push_back(ans);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            ans.push_back(nums[i]);

            solve(nums, ans, i + 1, subsets);

            // BACKTRACK
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> subsets;
        vector<int> ans;

        solve(nums, ans, 0, subsets);

        return subsets;
    }
};
