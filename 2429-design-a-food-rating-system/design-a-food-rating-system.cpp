#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    // maps food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    // maps cuisine -> ordered set of { -rating, food }
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        // update info
        foodInfo[food].second = newRating;
        // insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // first element in set = highest rating, lexicographically smallest
        return cuisineFoods[cuisine].begin()->second;
    }
};
