class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mp;
        for(int right = 0 ;right<nums.size();right++){
            int y = target - nums[right];
            if(mp.find(y) != mp.end()){
                return {mp[y],right};
            }
            mp[nums[right]] = right;
        }
    }
};
