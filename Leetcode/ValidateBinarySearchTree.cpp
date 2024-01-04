#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTExt(-(long long)pow(2, 31) - 1, (long long)pow(2, 31), root);
    }
    bool isValidBSTExt(long long min, long long max, TreeNode* root)
    {
        if (!root) return true;
        if (root->right) if (root->right->val <= root->val || root->right->val >= max) return false;
        if (root->left) if (root->left->val >= root->val || root->left->val <= min) return false;
        return isValidBSTExt((long long)root->val, max, root->right) && isValidBSTExt(min, (long long)root->val, root->left);
    }
};