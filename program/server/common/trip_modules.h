#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

//基础数据结构定义
struct Place {
    string name;
    string in_province;     // 所在省份
    vector<string> tags;    // 兴趣标签
    int time_needed;        // 游玩时间 （小时）
    double cost;            // 费用
    float score;            // 评分
};

struct Transport {
    string type;    // 交通方式
    double time;    // 时间（小时） 
    double cost;    // 费用
    string from;    // 出发地
    string to;      // 目的地
    Transport() {}
    Transport(string t, double ti, double c, string f, string to_)
        : type(t), time(ti), cost(c), from(f), to(to_) {}
};

struct Restaurant {
    string name;
    string in_province;             // 所在省份
    vector<string> taste;           // 口味
    double rating;                  // 评分
    double avgCost;                 // 平均消费
};

struct Schedule {
    Place place;                     //游玩地点
    Transport transport;             //交通方式
    int visit_time;                  //旅游时长
    Schedule() : transport("", 0, 0, "", "") {}
};

struct FinalPlan {
    vector<Schedule> schedules;     //安排行程
    double total_cost;              //总费用
    int total_time;                 //总时间
};

//模块类声明===================================================

// ========== 模块1+模块4：推荐模块（地点+餐饮） ==========
class RecommendModule {
private:
    vector<Place> all_places;
    vector<Restaurant> all_restaurants;
public:
    RecommendModule(vector<Place> places, vector<Restaurant> restaurants) 
        : all_places(places), all_restaurants(restaurants) {}

    // 按兴趣、旅行时间筛选地点（支持多日）
    vector<Place> recommend_places(string interest, int max_daily_time);

    // 按口味、游玩时间匹配餐饮
    vector<Restaurant> recommend_restaurants(string taste, double max_cost);
};

// ========== 模块2：行程模块 ==========
class ScheduleModule {
private:
    vector<Transport> all_transports;
    int daily_time_limit=8; // 每日最大游玩时间
public:
    ScheduleModule(vector<Transport> transports, int time_limit)
        : all_transports(transports), daily_time_limit(time_limit) {}

    // 总体多日行程安排
    vector<Schedule> total_trip_schedule(string first_place,vector<Place> selected_places, vector<Transport> selected_transports, int total_time_limit);
};

// ========== 模块3：交通模块（独立封装） ==========
class TransportModule {
private:
    vector<Transport> all_transports;
public:
    TransportModule(vector<Transport> transports) : all_transports(transports) {}

    // 选择两点间最优交通（时间+费用权重）
    Transport select_optimal_transport(string from, string to);
};

// ========== 模块5：最终方案模块（汇总） ==========
class FinalPlanModule {
public:
    // 汇总多日行程生成最终方案
    FinalPlan generate_final_plan(vector<Place> selected_places, vector<Transport> selected_transports, int total_time_limit, double total_budget);

    // 导出JSON供前端读取
    void export_to_json(const FinalPlan& plan, const string& filename = "data.json");
};
