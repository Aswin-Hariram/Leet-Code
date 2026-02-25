class Solution {
private:
    int findOne(int n){
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        for(int i:arr){
            q.push({findOne(i),i});
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;

        
    }
};