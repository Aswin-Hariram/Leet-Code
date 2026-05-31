class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();

        long long temp = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){
            if(temp>=asteroids[i]){
                temp += asteroids[i];

            }
            else{
                return false;
            }
        }
        return true;
    }
};