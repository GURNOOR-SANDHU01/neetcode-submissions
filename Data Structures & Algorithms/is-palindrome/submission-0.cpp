class Solution {
public:
    bool isPalindrome(string s) {

        string t = "";

        
        for (char c : s) {

            if (isalnum(c)) {
                t += tolower(c);
            }
        }

        
        int left = 0;
        int right = t.size() - 1;

        while (left < right) {

            if (t[left] != t[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};