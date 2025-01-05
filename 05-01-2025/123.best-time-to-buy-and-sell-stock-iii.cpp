class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    int ans = 0;

    int mn = prices[0];
    int bestProfit = 0;
    for (int i = 1; i < n + 1; i++)
    {
      bestProfit = max(bestProfit, prices[i - 1] - mn);
      mn = min(mn, prices[i - 1]);
      dp[i][1] = bestProfit;
    }

    int mx = n;
    bestProfit = 0;
    for (int i = n; i > 0; i--)
    {
      bestProfit = max(bestProfit, prices[mx - 1] - prices[i - 1]);
      dp[i][2] = bestProfit + dp[i][1];

      if (prices[mx - 1] < prices[i - 1])
      {
        mx = i;
      }
    }

    mn = 1;
    for (int i = 1; i < n + 1; i++)
    {
      dp[i][2] = max(dp[i][2], prices[i - 1] - prices[mn - 1] + dp[mn][1]);

      if (prices[mn - 1] > prices[i - 1])
      {
        mn = i;
      }
    }

    for (int i = 0; i < n + 1; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};