class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1,nums.end());
        int sum = 0;
        int f3 = 3;
        for(int n:nums){
            if(f3==0) break;
            f3--;
            cout<<n<<" ";
            sum+=n;
        }
        return sum;
    }
};