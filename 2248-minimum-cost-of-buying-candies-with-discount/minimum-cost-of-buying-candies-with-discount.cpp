class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n =cost.size();
        if(n==1) return cost[0];
        if(n==2) return cost[0]+cost[1];

        sort(cost.begin(),cost.end());
        int sum = 0;
        int i=n-1;
        while(i>=0){
            int first = cost[i];
            int second=0;
            if(i-1 >= 0){
                second = cost[i-1];
            }
            cout<<"Buying "<<first<<" and "<<second<<endl;
            sum += first+second;
            i-=3;

        }
        return sum;


    }
};


// 1 3 3 3
//