class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int start = edge[0], end = edge[1], weight = edge[2];
            adjList[start].push_back({end, weight});
            adjList[end].push_back({start, weight});
        }

        vector<int> result(n, INT_MAX);
        result[0] = 0;
           priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0}); 
        unordered_set<int> visited;
        while (!minHeap.empty()) {
           auto [time, node] = minHeap.top();
            minHeap.pop();
            if (visited.count(node) || time >= disappear[node]) {
                continue;
            }
            visited.insert(node);
              for (const auto& [neighbor, edgeWeight] : adjList[node]) {
                int newTime = time + edgeWeight;
                   if (newTime < result[neighbor] && newTime < disappear[neighbor]) {
                    result[neighbor] = newTime;
                      minHeap.push({newTime, neighbor});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (result[i] >= disappear[i]) {
            result[i] = -1;
            }
        }
        return result;
    }
};