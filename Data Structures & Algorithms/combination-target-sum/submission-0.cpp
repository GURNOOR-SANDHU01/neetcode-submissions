class Solution {
public:
    void combsum(vector<int>& nums, int i, vector<int>& combination,
                 vector<vector<int>>& ans, int target) {

        
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (target < 0 || i == nums.size()) {
            return;
        }

        
        combination.push_back(nums[i]);
        combsum(nums, i, combination, ans, target - nums[i]);
        combination.pop_back();

        
        combsum(nums, i + 1, combination, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        vector<vector<int>> ans;

        combsum(nums, 0, combination, ans, target);

        return ans;
    }
};
