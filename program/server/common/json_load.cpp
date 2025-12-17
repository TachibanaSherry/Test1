#include <fstream>
#include <vector>
#include "trip_modules.h"
#include "json.hpp"

using json = nlohmann::json;

// 读取地点数据
vector<Place> load_places_from_json(const string& filename) {
    vector<Place> places;
    ifstream file(filename);
    json data = json::parse(file);
    
    for (auto& item : data["places"]) {
        Place p;
        p.name = item["name"];
        p.tags = item["tags"].get<vector<string>>();
        p.time_needed = item["time_needed"];
        p.cost = item["cost"];
        p.score = item["score"];
        places.push_back(p);
    }
    return places;
}

// 读取交通数据（同理可编写读取餐饮数据的函数）
vector<Transport> load_transports_from_json(const string& filename) {
    vector<Transport> transports;
    ifstream file(filename);
    json data = json::parse(file);
    
    for (auto& item : data["transports"]) {
        Transport t;
        t.from = item["from"];
        t.to = item["to"];
        t.type = item["type"];
        t.time = item["time"];
        t.cost = item["cost"];
        transports.push_back(t);
    }
    return transports;
}
