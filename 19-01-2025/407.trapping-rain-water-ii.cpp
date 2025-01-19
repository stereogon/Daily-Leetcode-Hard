class Solution
{
public:
  bool isValid(int r, int c, int n, int m)
  {
    return r >= 0 && c >= 0 && r < n && c < m;
  }

  int trapRainWater(vector<vector<int>> &heightMap)
  {
    vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int n = heightMap.size();
    int m = heightMap[0].size();

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
        {
          pq.push(make_pair(heightMap[i][j], make_pair(i, j)));
          visited[i][j] = true;
        }
      }
    }

    int ans = 0;

    while (!pq.empty())
    {
      pair<int, pair<int, int>> cell = pq.top();
      pq.pop();

      int r = cell.second.first;
      int c = cell.second.second;
      int height = cell.first;

      for (int i = 0; i < 4; i++)
      {
        int nR = r + d[i][0];
        int nC = c + d[i][1];

        if (isValid(nR, nC, n, m) && !visited[nR][nC])
        {
          ans += max(0, height - heightMap[nR][nC]);
          visited[nR][nC] = true;
          pq.push(make_pair(max(height, heightMap[nR][nC]),
                            make_pair(nR, nC)));
        }
      }
    }

    return ans;
  }
};