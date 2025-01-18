class Solution
{
public:
  pair<int, int> getNextPosition(pair<int, int> node,
                                 vector<vector<int>> &grid)
  {

    pair<int, int> nextPosition;

    switch (grid[node.first][node.second])
    {
    case 1:
      nextPosition = make_pair(node.first, node.second + 1);
      break;
    case 2:
      nextPosition = make_pair(node.first, node.second - 1);
      break;
    case 3:
      nextPosition = make_pair(node.first + 1, node.second);
      break;
    case 4:
      nextPosition = make_pair(node.first - 1, node.second);
      break;
    }

    return nextPosition;
  }

  bool validPosition(pair<int, int> node, int n, int m)
  {
    int r = node.first;
    int c = node.second;

    if (r >= 0 && c >= 0 && r < n && c < m)
      return true;
    return false;
  }

  int minCost(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        q;
    q.push(make_pair(0, make_pair(0, 0)));

    vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));

    while (!q.empty())
    {
      pair<int, pair<int, int>> nodeCost = q.top();
      q.pop();

      pair<int, int> node = nodeCost.second;
      int cost = nodeCost.first;
      pair<int, int> nextPosition = getNextPosition(node, grid);

      if (validPosition(nextPosition, n, m))
      {
        if (cost < minCost[nextPosition.first][nextPosition.second])
        {
          q.push(make_pair(cost, nextPosition));
          minCost[nextPosition.first][nextPosition.second] = cost;
        }
      }

      int originalDir = grid[node.first][node.second];

      for (int i = 1; i <= 4; i++)
      {
        if (i == originalDir)
          continue;
        grid[node.first][node.second] = i;

        pair<int, int> np = getNextPosition(node, grid);

        if (validPosition(np, n, m))
        {
          if (cost + 1 < minCost[np.first][np.second])
          {
            q.push(make_pair(cost + 1, np));
            minCost[np.first][np.second] = cost + 1;
          }
        }
      }

      grid[node.first][node.second] = originalDir;
    }

    return minCost[n - 1][m - 1] == INT_MAX ? 0 : minCost[n - 1][m - 1];
  }
};
