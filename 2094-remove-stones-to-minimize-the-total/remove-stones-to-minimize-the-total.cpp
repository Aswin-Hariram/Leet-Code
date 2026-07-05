#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // max heap to store stones in piles
        priority_queue<int> maxHeap;
        int totalStones = 0;

        // Push all piles into maxHeap and calculate total stones
        for (int pile : piles) {
            maxHeap.push(pile);
            totalStones += pile;
        }

        // Perform k operations
        while (k-- > 0 && !maxHeap.empty()) {
            int curr = maxHeap.top();
            maxHeap.pop();

            int removed = curr / 2;
            totalStones -= removed;

            // Push remaining stones back if > 0
            int left = curr - removed;
            if (left > 0) {
                maxHeap.push(left);
            }
        }

        return totalStones;
    }
};
