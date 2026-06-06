class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
       
        for(int i=1;i<n;i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
        }

        for(int s:leftsum){
            cout<<s<<" ";
        }

        cout<<endl;

        for(int i=n-2;i>=0;i--){
            rightsum[i] = rightsum[i+1]+nums[i+1];
        }

        for(int s:rightsum){
            cout<<s<<" ";
        }

        vector<int> res(n);

        for(int i=0;i<n;i++){
            res[i] = abs(rightsum[i] - leftsum[i]);
        }

        cout<<endl;
        

        return res;
    }
};