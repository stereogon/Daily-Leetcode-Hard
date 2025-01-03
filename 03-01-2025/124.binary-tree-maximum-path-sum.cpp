/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  int solve(TreeNode *root, int &ans)
  {
    if (root == nullptr)
      return 0;
    int bestLeftSeq = solve(root->left, ans);
    int bestRightSeq = solve(root->right, ans);

    ans = max({ans, bestLeftSeq + root->val, bestRightSeq + root->val,
               root->val, bestLeftSeq + root->val + bestRightSeq});

    return max({bestLeftSeq, bestRightSeq, 0}) + root->val;
  }

  int maxPathSum(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int ans = -1001;
    solve(root, ans);
    return ans;
  }
};
