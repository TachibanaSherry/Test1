#include <trip_modules.h>
#include <vector>

Transport TransportModule::select_optimal_transport(string from, string to){
    vector<Transport> recommendations;
    for (auto& transport:all_transports){
        if (transport.from == from && transport.to == to){
            recommendations.push_back(transport);
        }
    }
    // 按时间费用分配权重排序，优先推荐时间短、费用低的交通方式
    sort(recommendations.begin(), recommendations.end(), [](const Transport& a, const Transport& b) {
        double rating_a = a.time * 0.65 + a.cost * 0.35;
        double rating_b = b.time * 0.65 + b.cost * 0.35;
        if (rating_a == rating_b) {
            return a.cost < b.cost;
        }
        return a.time < b.time;
    });
    return recommendations.empty() ? Transport("", 0, 0, "", "") : recommendations[0];
}