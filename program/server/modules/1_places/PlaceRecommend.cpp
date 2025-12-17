#include <vector>
#include <trip_modules.h>

vector<Place> RecommendModule::recommend_places(string interest, int max_daily_time) {
    vector<Place> recommendations;
    for (const auto& place : all_places) {
        if (place.time_needed <= max_daily_time) {
            if (find(place.tags.begin(), place.tags.end(), interest) != place.tags.end()) {
                recommendations.push_back(place);
            }
        }
    }
    // 按评分排序，评分高的优先推荐
    sort(recommendations.begin(), recommendations.end(), [](const Place& a, const Place& b) {
        return a.score > b.score;
    });
    return recommendations;
}