class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };
        
        priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            pq.push({gain(pass, total), {pass, total}});
        }
        
        while (extraStudents--) {
            auto [g, p] = pq.top(); pq.pop();
            int pass = p.first, total = p.second;
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
        }
        
        double sum = 0;
        while (!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            sum += (double)p.first / p.second;
        }
        
        return sum / classes.size();
    }
};