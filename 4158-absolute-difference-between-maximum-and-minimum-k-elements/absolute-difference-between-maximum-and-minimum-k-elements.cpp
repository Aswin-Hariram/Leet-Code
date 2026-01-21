class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        if(nums.size()<=k) return 0;

        sort(nums.begin(),nums.end());

        int Lsum = 0,Ssum = 0;
        int k1 = k;
        for(int i=nums.size()-1;i>=0&&k1>0;i--){
            Lsum += nums[i];
            k1--;
        }
        for(int i=0;i<nums.size()&&k>0;i++){
            Ssum += nums[i];
            k--;
        }
        cout<<Lsum<<" "<<Ssum<<endl;
        return abs(Lsum-Ssum);

    }
};