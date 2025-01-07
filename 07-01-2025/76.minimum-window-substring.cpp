class Solution
{
public:
  bool checkIncludes(unordered_map<char, int> &t_freq, unordered_map<char, int> &sub_freq)
  {
    for (auto [c, freq] : t_freq)
    {
      if (sub_freq.count(c) > 0 && sub_freq[c] >= freq)
      {
        continue;
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  string minWindow(string s, string t)
  {
    int n = s.size();
    int m = t.size();

    unordered_map<char, int> t_freq;
    unordered_map<char, int> sub_freq;

    for (int i = 0; i < m; i++)
    {
      t_freq[t[i]] += 1;
    }

    int l = 0;
    int r = 0;

    int bestL = -1;
    int mn = INT_MAX;

    while (r < n)
    {
      sub_freq[s[r]] += 1;
      r += 1;

      while (l < r && checkIncludes(t_freq, sub_freq))
      {
        int substringLength = r - l;
        if (substringLength < mn)
        {
          mn = substringLength;
          bestL = l;
        }

        sub_freq[s[l]] -= 1;
        l += 1;
      }
    }

    return mn == INT_MAX ? "" : s.substr(bestL, mn);
  }
};