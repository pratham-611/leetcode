class Solution {
public:
    void inorder(TreeNode* root , vector<int>& ans){
        if(root == NULL ) return ;
        
        inorder(root->left , ans);

        ans.push_back(root->val);

        inorder(root->right , ans);
    }

    bool find(vector<int>& ans , int k, int i , int j){
        if(i==j) return false;
        if(ans[i] + ans[j] == k) return true;

        else if(ans[i] + ans[j] < k) {
            return find(ans , k ,i+1,j);
        }
        else {
            return find(ans , k ,i,j-1);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root , ans);
        int n= ans.size();
        return find(ans , k ,0,n-1);
    }
};