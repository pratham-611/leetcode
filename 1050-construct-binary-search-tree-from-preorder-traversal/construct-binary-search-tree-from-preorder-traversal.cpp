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
class Solution {
public:
    TreeNode* constructBst(vector<int>& preorder, int l, int r){
        if(l > r){
            return NULL;
        }

        TreeNode * root = new TreeNode(preorder[l]);
        if(l == r){
            return root;
        }
        int maxi = -1;
        for(int i = l+1; i<=r; i++){
            if(preorder[l] < preorder[i]){
                maxi = i;
                break;
            }
        }
        
        if(maxi != -1){
            TreeNode* left = constructBst(preorder,l+1, maxi-1);
            TreeNode* right = constructBst(preorder,maxi, r);
            root->right = right;
            root->left = left;
        }
        else{
            TreeNode* left = constructBst(preorder,l+1,r);
            root->left = left;
        }
        
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBst(preorder, 0, preorder.size()-1);
    }
};

// [15,13,12,18]


