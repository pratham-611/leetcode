class Solution {
public:
    TreeNode* build(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie) {
        if (ps > pe) return NULL;

        TreeNode* root = new TreeNode(pre[ps]);

        int i = is;
        while (in[i] != pre[ps]) i++;

        int left = i - is;

        root->left = build(pre, in, ps + 1, ps + left, is, i - 1);
        root->right = build(pre, in, ps + left + 1, pe, i + 1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};