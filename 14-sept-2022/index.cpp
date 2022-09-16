/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void utility(TreeNode *root, vector<int> freq, int &count)
    {
        if (root == NULL)
            return;

        freq[root->val]++;
        utility(root->left, freq, count);
        if (root->left == NULL && root->right == NULL)
        {
            int oddCount = 0;
            for (auto x : freq)
            {
                if (x % 2 == 1)
                    oddCount++;
            }
            if (oddCount <= 1)
                count++;
        }
        utility(root->right, freq, count);
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);
        int count = 0;
        utility(root, freq, count);
        return count;
    }
};