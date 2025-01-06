class Solution
{
public:
  int solve(int day, int canBuy, int transactionsLeft, vector<int> &prices, vector<vector<vector<int>>> &memo)
  {
    if (day > prices.size())
      return 0;
    if (transactionsLeft == 0)
      return 0;

    if (memo[day][transactionsLeft][canBuy] != -1)
    {
      return memo[day][transactionsLeft][canBuy];
    }

    int ans = 0;
    if (canBuy)
    {
      ans = max(ans, -1 * prices[day - 1] + solve(day + 1, 0, transactionsLeft, prices, memo));
      ans = max(ans, solve(day + 1, canBuy, transactionsLeft, prices, memo));
    }
    else
    {
      ans = max(ans, prices[day - 1] + solve(day + 1, 1, transactionsLeft - 1, prices, memo));
      ans = max(ans, solve(day + 1, canBuy, transactionsLeft, prices, memo));
    }

    return memo[day][transactionsLeft][canBuy] = ans;
  }

  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return solve(1, 1, k, prices, memo);
  }
};