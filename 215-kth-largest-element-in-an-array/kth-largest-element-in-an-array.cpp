class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());

       

        while(!pq.empty()&&k-->1){
            cout<<pq.top()<<endl;
            pq.pop();
        }
        return pq.top();
    }
};