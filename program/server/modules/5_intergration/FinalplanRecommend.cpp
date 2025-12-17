#include <vector>
#include <trip_modules.h>

FinalPlan FinalPlanModule::generate_final_plan(vector<Place> selected_places, vector<Transport> selected_transports, int total_time_limit, double total_budget) {
    FinalPlan plan;
    plan.total_cost = 0;
    plan.total_time = 0;

    for (const auto& place : selected_places) {
        if (plan.total_time + place.time_needed > total_time_limit) {
            break; // 超出时间限制，停止添加地点
        }
        Schedule schedule;
        schedule.place = place;
        schedule.visit_time = place.time_needed;

        // 查找合适的交通方式
        for (const auto& transport : selected_transports) {
            if (transport.to == place.name) {
                schedule.transport = transport;
                break;
            }
        }

        plan.schedules.push_back(schedule);
        plan.total_time += place.time_needed;
        plan.total_cost += place.cost + schedule.transport.cost;

        if (plan.total_cost > total_budget) {
            plan.schedules.pop_back(); // 超出预算，移除最后添加的地点
            break;
        }
    }

    return plan;
}