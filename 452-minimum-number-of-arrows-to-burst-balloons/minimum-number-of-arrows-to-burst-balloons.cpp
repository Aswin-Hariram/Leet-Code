#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        // Sort balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int arrows = 1; // At least one arrow needed
        int arrowPos = points[0][1]; // Shoot arrow at end of first balloon

        for(int i = 1; i < (int)points.size(); i++) {
            // If current balloon starts after arrow position, new arrow needed
            if(points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
            // Else current arrow can burst this balloon, continue
        }

        return arrows;
    }
};