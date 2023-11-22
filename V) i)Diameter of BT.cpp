class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root,int& res){
        if(root==nullptr) return 0;
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        int temp=1+max(l,r);
        res=max(res,1+l+r);
        return temp;
    }
    int diameter(Node* root) {
        int res=INT_MIN;
        if(root==nullptr) return 0;
        solve(root,res);
        return res;
    }
};
