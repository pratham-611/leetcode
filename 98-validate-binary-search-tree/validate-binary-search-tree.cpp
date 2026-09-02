class Solution {
public:
    bool check(TreeNode* root, long long lo, long long hi) {
        if (!root) return true;

        if (root->val <= lo || root->val >= hi)
            return false;

        return check(root->left, lo, root->val) &&
               check(root->right, root->val, hi);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};