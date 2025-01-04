class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    int ml = height[0];
    int mr = height[n - 1];

    int l = 0;
    int r = n - 1;

    int ans = 0;

    while (l < r)
    {
      if (ml < mr)
      {
        l += 1;
        ml = max(ml, height[l]);
        ans += max(0, ml - height[l]);
      }
      else
      {
        r -= 1;
        mr = max(mr, height[r]);
        ans += max(0, mr - height[r]);
      }
    }

    return ans;
  }
};