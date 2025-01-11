class Solution
{
public:
  int shortestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> minHeap;
    long long int ans = LLONG_MAX;
    long long int prefix = 0L;

    for (int i = 0; i < n; i++)
    {
      prefix += nums[i];
      if (prefix >= k)
        ans = min(ans, i + 1LL);
      while (!minHeap.empty() && (prefix - minHeap.top().first >= k))
      {
        pair<int, int> top = minHeap.top();
        ans = min(ans, (long long int)i - top.second);
        minHeap.pop();
      }

      minHeap.push(make_pair(prefix, i));
    }

    return ans == INT_MAX ? -1 : ans;
  }
};