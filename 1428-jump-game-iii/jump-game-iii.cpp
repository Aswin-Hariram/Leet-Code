class Solution {
public:

    bool solve(vector<int>& arr, int start,vector<bool> &vis,vector<bool> &rec,int n){
        if(start<0 || start>= n) return false;
        if(arr[start]==0) return true;
        if(rec[start]) return false;
        
        rec[start] = true;
        bool pos = solve(arr,start+arr[start],vis,rec,n);

        bool neg = solve(arr,start-arr[start],vis,rec,n);
        rec[start] = false;
        return pos||neg;

    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> rec(n,false);
        vector<bool> vis(n,false);
        bool ans = solve(arr,start,vis,rec,n);
        return ans;
    }
};