class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int num:nums){
            if(st.count(num)){
                return true;
            }
            st.insert(num);
        }
        return false;
    }
};