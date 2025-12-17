#include <vector>
#include <limits>
#include <string>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

class Location_Graph {
public:
    Location_Graph();
    ~Location_Graph(); 
    void create_graph(const vector<string>& locations);
private:
    int vertex_count;
    int edges[100][100];
    vector<string> vertex_names;
};

void Location_Graph::create_graph(const vector<string>& locations) {
    vertex_count = locations.size();
    vertex_names = locations;
    for (int i = 0; i < vertex_count; ++i) {
        for (int j = 0; j < vertex_count; ++j) {
            if (i == j) {
                edges[i][j] = 0;
            } else {
                edges[i][j] = numeric_limits<int>::max(); // 初始化为无穷大，表示不可达
            }
        }
    }
}