class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int effort = max(dist[x][y], abs(heights[nx][ny] - heights[x][y]));
                    if (effort < dist[nx][ny]) {
                        dist[nx][ny] = effort;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
