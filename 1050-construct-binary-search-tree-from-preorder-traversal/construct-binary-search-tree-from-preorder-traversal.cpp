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

    vector<int> ng;

    void getNextGreater(vector<int>& preorder){
        stack<int> st;
        st.push(-1);
        for(int i = preorder.size()-1; i>=0; i--){
            if(st.top() == -1){
                ng.push_back(-1);
            }
            else{
                while(st.top() != -1 && preorder[i] >= preorder[st.top()]){
                    st.pop();
                }
                ng.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ng.begin(), ng.end());
    }

    TreeNode* constructBst(vector<int>& preorder, int l, int r){
        if(l > r){
            return NULL;
        }

        TreeNode * root = new TreeNode(preorder[l]);
        if(l == r){
            return root;
        }
        int maxi = ng[l];
        
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
        getNextGreater(preorder);
        return constructBst(preorder, 0, preorder.size()-1);
    }
};

// [15,13,12,18]


