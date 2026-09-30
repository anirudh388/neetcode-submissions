class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        unordered_set<int> mp;

        for (int i = 0; i < n; i++) {
            mp.insert(nums[i]);
        }

        int longest = 1;

        for (auto it : mp) {

            if (mp.find(it - 1) == mp.end()) {

                int count = 1;
                int x = it;

                while (mp.find(x + 1) != mp.end()) {
                    count++;
                    x++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
