class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int num:nums){

            for(char s : to_string(num)){
                ans.push_back(s-'0');
            }
        }
        return ans;
    }
};