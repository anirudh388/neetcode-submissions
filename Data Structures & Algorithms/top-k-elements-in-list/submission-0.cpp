class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        while(k--){
            int maxFreq=0;
            int element=0;
            for(auto x:mp){
                if(x.second>maxFreq){
                    maxFreq=x.second;
                    element=x.first;
                }
            }
            ans.push_back(element);
            mp.erase(element);
        }
        return ans;
    }
};