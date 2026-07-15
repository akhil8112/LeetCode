class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> rev(n);
        for (auto &it : edges) {
            rev[it[1]].push_back(it[0]);
        }

        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {

            vector<int> vis(n, 0);
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : rev[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                if (vis[j]) ans[i].push_back(j);
            }
        }

        return ans;
    }
};