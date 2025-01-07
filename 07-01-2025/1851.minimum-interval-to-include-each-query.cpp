class Solution
{
public:
  vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
  {
    int n = intervals.size();
    int m = queries.size();

    sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b)
         { return (a[1] - a[0]) < (b[1] - b[0]); });

    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
      st.insert(make_pair(queries[i], i));
    }

    vector<int> ans(m, -1);

    for (int i = 0; i < n; i++)
    {
      vector<int> interval = intervals[i];
      auto val = st.lower_bound({interval[0], -1});
      auto start = val;
      while (val != st.end() && val->first <= interval[1])
      {
        ans[val->second] = interval[1] - interval[0] + 1;
        val++;
      }

      st.erase(start, val);
    }

    return ans;
  }
};