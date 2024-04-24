
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> al(n);
        vector<vector<int>> cnt(n, vector<int>(26));
        vector<int> indegrees(n, 0);
        
        for (const auto& e : edges) {
            al[e[0]].push_back(e[1]);
            indegrees[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0)
                q.push(i);
        }
        
        int res = 0, processed = 0;
        while (!q.empty()) {
            queue<int> q1;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                processed++;
                res = max(res, ++cnt[i][colors[i] - 'a']);
                for (int j : al[i]) {
                    for (int k = 0; k < 26; k++)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indegrees[j] == 0)
                        q1.push(j);
                }
            }
            q = q1;
        }
        
        return processed != n ? -1 : res;
    }
};
   