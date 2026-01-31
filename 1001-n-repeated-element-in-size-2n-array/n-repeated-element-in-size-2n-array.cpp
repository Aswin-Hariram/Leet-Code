class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mapp;
        int n = nums.size()/2;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
            if(mapp[nums[i]]==n){
                return nums[i];
            }
        }
        return -1;
    }
};