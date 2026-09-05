class Solution {
public:

    void getAllSubsets(vector<int>& nums,
                       vector<int>& ans,
                       int i,
                       vector<vector<int>>& allSubsets) {

        // Base case
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // TAKE
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // UNDO
        ans.pop_back();

        // DON'T TAKE
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};
