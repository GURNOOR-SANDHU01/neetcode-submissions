class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int ans = 0;

        while (left < right) {

            int minhight = min(heights[left], heights[right]);
            int width = right - left;

            int countans = width * minhight;

            ans = max(ans, countans);

            
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
  
