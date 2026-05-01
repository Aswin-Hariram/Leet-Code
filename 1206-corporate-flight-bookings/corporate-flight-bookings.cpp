class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);

        

        for(auto b:bookings){
            int s = b[0]-1;
            int e = b[1]-1;
            int seat = b[2];
            if(s<0 || e>=n) continue;
            for(int i=s;i<=e;i++){
                res[i] += seat;
            }
        }
        return res;
        
    }
};