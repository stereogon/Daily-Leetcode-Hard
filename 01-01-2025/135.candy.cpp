class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int n = ratings.size();
    int ans = 0;

    vector<int> indexes;
    for (int i = 0; i < n; i++)
    {
      indexes.push_back(i);
    }

    sort(indexes.begin(), indexes.end(),
         [&](int a, int b)
         { return ratings[a] < ratings[b]; });

    vector<int> candies(n, -1);

    for (int i = 0; i < n; i++)
    {
      int index = indexes[i];
      int temp = 0;

      if (index - 1 >= 0)
      {
        if (ratings[index - 1] == ratings[index])
        {
          temp = 1;
        }
        else
        {
          temp = max(1, candies[index - 1] + 1);
        }
      }

      if (index + 1 < n)
      {
        if (ratings[index + 1] == ratings[index])
        {
          temp = max(temp, 1);
        }
        else
        {
          temp = max({temp, candies[index + 1] + 1, 1});
        }
      }

      candies[index] = temp;
    }

    for (int i = 0; i < n; i++)
    {
      ans += max(1, candies[i]);
    }

    return ans;
  }
};