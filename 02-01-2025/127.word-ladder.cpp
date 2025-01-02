class Solution
{
public:
  int ladderLength(string beginWord, string endWord,
                   vector<string> &wordList)
  {
    unordered_map<string, bool> mp;
    for (int i = 0; i < wordList.size(); i++)
    {
      mp[wordList[i]] = true;
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    mp[beginWord] = false;

    while (!q.empty())
    {
      pair<string, int> front = q.front();
      string word = front.first;
      int steps = front.second;
      if (word == endWord)
        return steps;

      q.pop();

      for (int i = 0; i < word.size(); i++)
      {
        char original = word[i];
        for (int j = 0; j < 26; j++)
        {
          word[i] = j + 'a';
          if (mp.count(word) > 0 && mp[word] == true)
          {
            q.push({word, steps + 1});
            mp[word] = false;
          }
        }

        word[i] = original;
      }
    }

    return 0;
  }
};