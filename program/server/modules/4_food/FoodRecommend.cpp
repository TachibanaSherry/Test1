#include <vector>
#include <trip_modules.h>

vector<Restaurant> RecommendModule::recommend_restaurants(string taste, double max_cost) {
    vector<Restaurant> recommendations;
    for (const auto& restaurant : all_restaurants) {
        if (restaurant.avgCost <= max_cost) {
            if (find(restaurant.taste.begin(), restaurant.taste.end(), taste) != restaurant.taste.end()) {
                recommendations.push_back(restaurant);
            }
        }
    }
    // 按评分排序，评分高的优先推荐
    sort(recommendations.begin(), recommendations.end(), [](const Restaurant& a, const Restaurant& b) {
        return a.rating > b.rating;
    });
    return recommendations;
}